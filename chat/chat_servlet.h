#ifndef _CHAT_CHAT_SERVLET_H_
#define _CHAT_CHAT_SERVLET_H_

#include"JKYi/http/ws_servlet.h"

namespace chat{

class ChatWSServlet:public JKYi::http::WSServlet{
public:
    typedef std::shared_ptr<ChatWSServlet> ptr;
    ChatWSServlet();

    virtual int32_t onConnect(JKYi::http::HttpRequest::ptr header,
                                JKYi::http::WSSession::ptr session)override;
    virtual int32_t onClose(JKYi::http::HttpRequest::ptr header,
                                JKYi::http::WSSession::ptr session)override;
    virtual int32_t handle(JKYi::http::HttpRequest::ptr headers,
                                JKYi::http::WSFrameMessage::ptr msg,
                                JKYi::http::WSSession::ptr session)override;
};

}

#endif
