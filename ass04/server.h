#ifndef SERVER_H_
#define SERVER_H_
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "CLI.h"
#include "SocketIO.h"
#include "Classifier.h"
#include <thread>
using namespace std;
class Server{
public:
//this function gets a string and if it contains a valid port number it returns it as int, otherwise it returns -1.
static int getPort(string port);
};
#endif