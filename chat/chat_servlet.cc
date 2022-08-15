#include"chat_servlet.h"
#include"JKYi/log.h"
#include"protocol.h"

namespace chat{

static JKYi::Logger::ptr g_logger = JKYI_LOG_ROOT();

JKYi::RWMutex m_mutex;
//存放的是当前的客户端你的id(name) - WSSession
std::map<std::string,JKYi::http::WSSession::ptr> m_sessions;

bool session_exists(const std::string& id){
    JKYI_LOG_INFO(g_logger) << " session_exists id = " <<id;
    JKYi::RWMutex::ReadLock lock(m_mutex);
    auto it = m_sessions.find(id);
    return it != m_sessions.end();
}

void session_add(const std::string& id,JKYi::http::WSSession::ptr session){
    JKYI_LOG_INFO(g_logger) << "session_add id = "<< id;
    JKYi::RWMutex::WriteLock lock(m_mutex);
    m_sessions[id] = session;
}

void session_del(const std::string& id){
    JKYI_LOG_INFO(g_logger) << "session_del id = " << id;
    JKYi::RWMutex::WriteLock lock(m_mutex);
    m_sessions.erase(id);
}

int32_t SendMessage(JKYi::http::WSSession::ptr session,
                      ChatMessage::ptr msg){
    JKYI_LOG_INFO(g_logger) << "SendMessage : " << msg->toString();
    return session->sendMessage(msg->toString()) > 0 ? 0 : 1;
}

void session_notify(ChatMessage::ptr msg,JKYi::http::WSSession::ptr session = nullptr){
    //减小锁的粒度
    JKYi::RWMutex::ReadLock lock(m_mutex);
    auto sessions = m_sessions;
    lock.unlock();

    for(auto& i : sessions){
        if(i.second == session){
            continue;
        }
        SendMessage(i.second,msg);
    }
    return ;
}

ChatWSServlet::ChatWSServlet()
    :JKYi::http::WSServlet("chat_servlet"){
}

int32_t ChatWSServlet::onConnect(JKYi::http::HttpRequest::ptr header,
                                   JKYi::http::WSSession::ptr session){
    JKYI_LOG_INFO(g_logger) << "onConnect";
    return 0;
}

int32_t ChatWSServlet::onClose(JKYi::http::HttpRequest::ptr header,
                                  JKYi::http::WSSession::ptr session){
    std::string id = header->getHeader("$id");
    JKYI_LOG_INFO(g_logger) << " onClose id = " << id;
    if(!id.empty()){
        session_del(id);
        ChatMessage::ptr nty(new ChatMessage);
        nty->set("type","user_leave");
        nty->set("time",JKYi::Time2Str());
        nty->set("name",id);
        session_notify(nty);
    }
    return 0;
}

int32_t ChatWSServlet::handle(JKYi::http::HttpRequest::ptr header,
                               JKYi::http::WSFrameMessage::ptr msg,
                               JKYi::http::WSSession::ptr session){
    JKYI_LOG_INFO(g_logger) << " handle opt = " << msg->getOpcode()
                            << " data = " << msg->getData();
    ChatMessage::ptr message = ChatMessage::Create(msg->getData());
    auto id = header->getHeader("$id");
    if(!message){
        if(!id.empty()){
            JKYi::RWMutex::WriteLock lock(m_mutex);
            m_sessions.erase(id);
        }
        return 1;
    }
    ChatMessage::ptr rsp(new ChatMessage);
    std::string type = message->get("type");
    if(type == "login_request"){
        //用户的登录请求
        rsp->set("type","login_response");
        std::string name = message->get("name");
        if(name.empty()){
            rsp->set("result","400");
            rsp->set("msg","name is null");
            return SendMessage(session,rsp);
        }
        if(!id.empty()){
            rsp->set("result","401");
            rsp->set("msg","logined");
            return SendMessage(session,rsp);
        }
        if(session_exists(name)){
            rsp->set("result","402");
            rsp->set("msg","id exists");
            return SendMessage(session,rsp);
        }
        //
        id = name;
        header->setHeader("$id",id);
        rsp->set("result","200");
        rsp->set("msg","OK");
        session_add(id,session);

        //通知其他人
        ChatMessage::ptr nty(new ChatMessage);
        nty->set("type","user_enter");
        nty->set("time",JKYi::Time2Str());
        nty->set("name",id);
        session_notify(nty,session);

        return SendMessage(session,rsp);
    }else if(type == "send_request"){
        //用户的发送信息
        rsp->set("type","send_response");
        std::string m = message->get("msg");
        if(m.empty()){
            rsp->set("result","500");
            rsp->set("msg","msg is null");
            return SendMessage(session,rsp);
        }
        if(id.empty()){
            rsp->set("result","501");
            rsp->set("msg","not login");
            return SendMessage(session,rsp);
        }

        rsp->set("result","200");
        rsp->set("msg","ok");

        ChatMessage::ptr nty(new ChatMessage);
        nty->set("type","msg");
        nty->set("time",JKYi::Time2Str());
        nty->set("name",id);
        nty->set("msg",m);
        session_notify(nty,nullptr);

        return SendMessage(session,rsp);
    }
    return 0;
}

}
