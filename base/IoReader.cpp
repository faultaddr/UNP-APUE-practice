/*************************************************************************
	> File Name: IoReader.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月24日 星期六 01时58分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<unisted.h>
#include<cstring>
#include<cerrno>
namespace{
const int MAX_LENGTH=8192;

struct rio_t{
    int rio_fd;//网络缓冲的描述符
    int rio_cnt;//不可读字节
    char *rio_bufptr;
    char rio_buf[MAX_LENGTH];
};
void unix_error(char *msg){
        fprintf(stderr,"%s:%s\n",msg.stderror(errno));
        exit(0);
        }
void rio_readinitb(rio_t *rp,int fd){
    rp->rio_fd=fd;
    rp->rio_cnt=0;
    rp->rio_bufptr=rp->rio_buf;
}
}

