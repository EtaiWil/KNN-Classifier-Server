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
using namespace std;
class Client{
public:
//this function check if the ip is valid.
static bool isValidIpAddress(char *ipAddress);
//this function gets a string and if it contains a valid port number it returns it as int, otherwise it returns -1.
static int getPort(string port);
//this function checks if the given distance metric is valid
static bool isValidDistance(std::string distance);
//this function checks if the given char is a dot, if so returns true,otherwise returns false.
static bool isDot(char c);
//this function checks if the given string contatins a valid double.
static bool isValidDouble(std::string s);
//this function gets an input from the user and stores it in a vector of strings (divides by spaces.)
static std::vector<std::string> getUserInput(string input);
//this function gets the vector we got from getUserInput function and gets the distance metric out of it.
//if the distance metric is invalid, it throws an exception.
static std::string getUserDistance(vector<std::string> input);
//this funciton check if the k that given by the user is valid.
static int getUserK(vector<std::string> input);
 // this function converting the input from string to double and store the values in vector.
static std::vector<double> getUserVector();
//this function runs the is valid double on every string in the vector. if one is not valid it returns false.
static bool isValidVector(std::vector<string> vec);

};


#endif