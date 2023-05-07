<<<<<<< HEAD:SocketIO.h

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
=======

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
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/SocketIO.h
