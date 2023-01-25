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
class Client
{
private:
    DefaultIO &dio;
    string message;
    // flag to know if the menu was printed
    bool isMenuPrinted;
    // check if the menu is a part of the message to set the flag.
    bool checkMessageForMenu();

public:
    // constructor
    Client(DefaultIO &dio);
    // get a message from the server
    string getMessage();
    // check if the menu was already printed
    bool isPrintMenu();
    // read a message from the given DefaultIO
    void readMessage();
    // write a message using the DefaultIO
    void writeMessage(string s);
    // upload vector files to server
    void uploadFiles();
    // view and set the algorithm settings
    void algoSetting(string setting);
    // request the server to classify the data
    void classify();
    // get the classifications from the server to the screen
    void getClassification();
    // get the classifications into a file.
    static void getClassificationToFile(string data,ofstream &&file);
        // this function check if the ip is valid.
        static bool isValidIpAddress(char *ipAddress);
    // this function gets a string and if it contains a valid port number it returns it as int, otherwise it returns -1.
    static int getPort(string port);
};

#endif