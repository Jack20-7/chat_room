#ifndef _CHAT_PROTOCOL_H_
#define _CHAT_PROTOCOL_H_

#include"JKYi/util/json_util.h"

#include<string>
#include<map>
#include<memory>

namespace chat{

class ChatMessage{
public:
    typedef std::shared_ptr<ChatMessage> ptr;

    static ChatMessage::ptr Create(const std::string& str);

    ChatMessage();
    std::string get(const std::string& name);
    void set(const std::string& name,const std::string& value);
    std::string toString()const;
private:
    std::map<std::string,std::string> m_datas;
};
}

#endif
