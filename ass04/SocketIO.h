
#ifndef SOCKETIO_H
#define SOCKETIO_H
#include "DefaultIO.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <stdexcept>

class SocketIO: public DefaultIO {
private:
    int sock;
public:
    SocketIO(int sock);
    //read a message from the socket
    virtual std::string read();
    // sending a message using the socket
    virtual void write(std::string s);

};


#endif
