#include "RequestCreater.h"

GetRequest RequestCreater::getHandler=GetRequest();
Request* RequestCreater::getRequestHandler(int fd,const std::string name,const std::string uri){
    if(name=="GET"){
        getHandler.init(fd,uri);
        return &getHandler;
    }
}
