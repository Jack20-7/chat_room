#include"resource_servlet.h"
#include"JKYi/log.h"

#include<iostream>
#include<fstream>

namespace JKYi{
namespace http{

static Logger::ptr g_logger = JKYI_LOG_ROOT();

ResourceServlet::ResourceServlet(const std::string& path)
    :Servlet("ResourceServlet"),
     m_path(path){
}

int32_t ResourceServlet::handle(JKYi::http::HttpRequest::ptr req,
                                 JKYi::http::HttpResponse::ptr rsp,
                                 JKYi::http::HttpSession::ptr session){

    std::string path = m_path + "/" + req->getPath();
    JKYI_LOG_INFO(g_logger) << "handle path = " << path;
    if(path.find("..") != std::string::npos){
        rsp->setBody("invalid file");
        rsp->setStatus(JKYi::http::HttpStatus::NOT_FOUND);
        return 0;
    }

    std::ifstream ifs(path);
    if(!ifs){
        rsp->setBody("invalid file");
        rsp->setStatus(JKYi::http::HttpStatus::NOT_FOUND);
        return 0;
    }

    std::stringstream ss;
    std::string line;
    while(std::getline(ifs,line)){
        ss << line <<std::endl;
    }
    
    rsp->setBody(ss.str());
    rsp->setHeader("content-type","text/html;charset=uft-8");
    return 0;
}

}
}

