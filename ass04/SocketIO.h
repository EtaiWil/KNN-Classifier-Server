
#ifndef SOCKETIO_H
#define SOCKETIO_H
#include "DefaultIO.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class SocketIO: public DefaultIO {
private:
    int sock;
public:
    SocketIO(int sock);
    virtual std::string read();
    virtual void write(std::string s);

};


#endif
