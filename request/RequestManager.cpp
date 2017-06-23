/*************************************************************************
	> File Name: RequestManager.cpp
	> Author:panyunyi
	> Mail: cufer@foxmail.com
	> Created Time: 2017年06月24日 星期六 01时29分31秒
 ************************************************************************/

#include<iostream>
#include"Request.h"
#include"RequestCreater.h"
#include"../base/IoReader.h"
namespace {
class Parser{
public:
    Parser(int connfd){
        parseRequestHeaders(connfd);
    }
    const std::string getMethodName(){
        return method;
    }
    const std::string getUri(){
        return uri;
    }
private:
    void parseRequestHeaders(int fd){
        Ioreader reader(fd);
        std::vector<std::string>header;
        reader.getLineSpliteByBlank(header);
        method=header[0];
        uri=header[1];
        version=header[2];
    }
private:
    std::string method;
    std::string uri;
    std::string version;

};
}
Requestmanager::RequestManager(int connfd):fileDescriptor(connfd),request(0){}
void RequestManager::run(){
    if(getRequestHandler())
        request->execute();
}
Request* RequestManager::getRequestHandler(){
    Parser parser(fileDescriptor);
    return request=RequestCreater::getRequestHandler(fileDescriptor,parser.getMethodName(),parser.getUri());

}


