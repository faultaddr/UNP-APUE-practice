/*************************************************************************
	> File Name: RequestManager.h
	> Author: 
	> Mail: 
	> Created Time: 2017年06月24日 星期六 01时28分40秒
 ************************************************************************/

#ifndef _REQUESTMANAGER_H
#define _REQUESTMANAGER_H
#include<string>

class Request;
class RequestManager{
public:
    RequestManager(int connfd);
    void run();
private:
    Request* getRequestHandler();
private:
    int fileDescriptor;
    Request* request;
}

#endif
