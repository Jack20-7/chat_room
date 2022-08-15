#include"protocol.h"
#include"JKYi/util.h"

namespace chat{

ChatMessage::ptr ChatMessage::Create(const std::string& str){
    Json::Value json;
    if(!JKYi::JsonUtil::FromString(json,str)){
        return nullptr;
    }
    ChatMessage::ptr rt(new ChatMessage);
    auto names = json.getMemberNames();
    for(auto& i : names){
        rt->m_datas[i] = json[i].asString();
    }
    return rt;
}

ChatMessage::ChatMessage(){
}

std::string ChatMessage::get(const std::string& name){
    auto it = m_datas.find(name);
    return it == m_datas.end() ? "" : it->second;
}

void ChatMessage::set(const std::string& name,const std::string& value){
    m_datas[name] = value;
}

std::string ChatMessage::toString()const{
    Json::Value json;
    for(auto& i : m_datas){
        json[i.first] = i.second;
    }
    return JKYi::JsonUtil::ToString(json);
}

}
