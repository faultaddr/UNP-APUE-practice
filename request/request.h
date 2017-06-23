#ifndef REQUSET_H
#define REQUEST_H

#include<string>

class Request{
public:
    void init(int fd,std::string uri);
    void execute();
    virtual ~Request(){}
protected:
    int getFileDescription const;
    const std::string& getUri() const;
private:
    int fileDescriptor;
    std::string uri;


}
#endif
