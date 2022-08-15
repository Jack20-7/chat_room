#include"my_module.h"
#include"JKYi/config.h"
#include"JKYi/log.h"
#include"JKYi/application.h"
#include"JKYi/http/ws_server.h"
#include"JKYi/env.h"
#include"resource_servlet.h"
#include"chat_servlet.h"

namespace chat{

static JKYi::Logger::ptr g_logger = JKYI_LOG_ROOT();

MyModule::MyModule()
    :JKYi::Module("chat_room","1.0",""){
}

bool MyModule::onLoad(){
    JKYI_LOG_INFO(g_logger) << "onload";
    return true;
}

bool MyModule::onUnload(){
    JKYI_LOG_INFO(g_logger) << "onUnload";
    return true;
}

bool MyModule::onServerReady(){
    JKYI_LOG_INFO(g_logger) << "onServerReady";
    std::vector<JKYi::TcpServer::ptr> svrs;
    if(!JKYi::Application::GetInstance()->getServer("http",svrs)){
        JKYI_LOG_ERROR(g_logger) << "no httpserver alive";
        return false;
    }
    for(auto & i : svrs){
       JKYi::http::HttpServer::ptr http_server = std::dynamic_pointer_cast<JKYi::http::HttpServer>(i);
       if(!i){
           continue;
       }

       auto slt_dispatch = http_server->getServletDispatch();

       JKYi::http::ResourceServlet::ptr slt(new JKYi::http::ResourceServlet(
                   JKYi::EnvMgr::GetInstance()->getCwd()
        ));
       slt_dispatch->addGlobServlet("/html/*",slt);
       JKYI_LOG_INFO(g_logger) << "addGlobServlet";
    }
    svrs.clear();

    if(!JKYi::Application::GetInstance()->getServer("ws",svrs)){
        JKYI_LOG_INFO(g_logger) << "not wsserver alive";
        return false;
    }
    for(auto& i : svrs){
        JKYi::http::WSServer::ptr ws_server = std::dynamic_pointer_cast<JKYi::http::WSServer>(i);

        JKYi::http::ServletDispatch::ptr slt_dispatch = ws_server->getWSServletDispatch();
        ChatWSServlet::ptr slt(new ChatWSServlet);
        slt_dispatch->addServlet("/JKYi/chat",slt);
    }
    return true;
}

bool MyModule::onServerUp(){
    JKYI_LOG_INFO(g_logger) << "onServerUp";
    return true;
}

}
extern "C"{

JKYi::Module* CreateModule(){
   JKYi::Module * module = new chat::MyModule;
   JKYI_LOG_INFO(chat::g_logger) << "CreateModule" << module;
   return module;
}

void DestroyModule(JKYi::Module * module){
    JKYI_LOG_INFO(chat::g_logger) << "DestroyModule";
    delete module;
}

  
}


