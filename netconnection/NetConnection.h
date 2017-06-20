#ifndef NET_CONNECTION_H
#define NET_CONNECTION_H
class NetConnection{
    public:
        NetConnection();
        void listen(int port);
        int accept();
        void close();
    private:
        int listenfd;
        int connfd;
}

#endif
