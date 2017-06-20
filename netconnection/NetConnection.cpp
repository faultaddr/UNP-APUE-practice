#include"NetConnection.h"

#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<cstring>
#include<cerrno>
#include<arpa/inet.h>
#include<sys/socket.h>

namespace {
    const int LISTENQ=1024;
    void unix_error(char *msg){
        fprintf(stderr,"%s:%s\n",msg,strerror(errno));
        exit(0);

    }


}

int open_listenfd(int port){
    int listenfd,optval=1;
    struct sockaddr_in servaddr;

    //create a socket descriptor
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0)
        return -1;
    if(setsockopt(listenfd,SQL_SOCKET,SO_REUSEADDR,(const void *)&optval,sizeof(int))<0)
        return -1;
    // listenfd will be an endport for all requests to port on any Ip address for this host
    bzero((char*)&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons((unsigned short)port);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    if(bind(listenfd,(sockaddr *)&servaddr,sizeof(servaddr))<0)
        return -1;
    //make it a listening socket ready to accept connection requests
    if(listen(listenfd,LISTENQ)<0)
        return -1;
    return listenfd;


}
int Open(int port){
    int result;
    if((result=open_listenfd(port))<0)
        unix_error("Open listenfd error");
    return result;

}

int Accept(int s,strcut sockaddr *addr,socklen_t *addrlen){
    int result;
    if((result=accept(s,addr,addrlen))<0)
        unix_error("Accept error");
    return result;
}

void Close(int fd){
    int result;
    if((result=close(fd))<0)
        unix_error("close error");
}

NetConnection::NetConnection():listenfd(-1),connfd(-1){

}
void NetConnection::listen(int port){
    listenfd=Open(port);
}
int NetConnection::accept(){
    int clientlen;
    struct sockaddr_in clientaddr;
    clientlen=sizeof(clientaddr);
    connfd=Accept(listenfd,(sockaddr *)&clientaddr,reinterpret_cast<socklen_t *>(&clientlen));
    return connfd;
}

void NetConnection::close(){
    Close(connfd);
}
