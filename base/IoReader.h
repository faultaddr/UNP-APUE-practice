/*************************************************************************
	> File Name: IoReader.h
	> Author: 
	> Mail: 
	> Created Time: 2017年06月24日 星期六 01时58分26秒
 ************************************************************************/

#ifndef _IOREADER_H
#define _IOREADER_H
#include<string>
#include<vector>
class IoReader{
public:
    IoReader(int fd);
    void getLineSpliteByBlank(std::vector<std::string>&buf);
};
#endif
