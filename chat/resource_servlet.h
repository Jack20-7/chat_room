#ifndef _JKYI_RESOURCE_SERVLET_H_
#define _JKYI_RESOURCE_SERVLET_H_

#include"JKYi/http/servlet.h"

namespace JKYi{
namespace http{

class ResourceServlet:public JKYi::http::Servlet{
public:
    typedef std::shared_ptr<ResourceServlet> ptr;
    ResourceServlet(const std::string& path);

    virtual int32_t handle(JKYi::http::HttpRequest::ptr req,
                           JKYi::http::HttpResponse::ptr rsp,
                            JKYi::http::HttpSession::ptr session)override;
private:
    std::string m_path;
};
}
}
#endif
