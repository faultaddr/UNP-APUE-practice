#include"Requset.h"
void Request::init(int fd,std::string uri){
    this->fileDescriptor=fd;
    this->uri=uri;
}
void Requset::execute(){
    doExecute();
}
int Requset::getFileDescriptor() const{
    return fileDescriptor;
}
const std::string& Request::getUri() const{
    return uri;
}
