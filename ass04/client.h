#ifndef CLIENT_H_
#define CLIENT_H_

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
#include "SocketIO.h"
#include "DefaultIO.h"
#include <thread>
#include <stdio.h>
using namespace std;
class Client{
private:
    DefaultIO &dio;
    string message;
    bool isMenuPrinted;
    bool checkMessageForMenu();

public:

Client(DefaultIO& dio);
string getMessage();
//string getMenu();
bool isPrintMenu();
void readMessage();
void writeMessage(string s);
void uploadFiles();
void algoSetting(string setting);
void classify();
void getClassification();
//this function check if the ip is valid.
static bool isValidIpAddress(char *ipAddress);
//this function gets a string and if it contains a valid port number it returns it as int, otherwise it returns -1.
static int getPort(string port);
};


#endif