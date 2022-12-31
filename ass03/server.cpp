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
#include "Classifier.h"
using namespace std;

// if port is invalid returs -1,otherwise returns the port number as int
int getPort(string port)
{
  std::size_t found = port.find_first_not_of("0123456789");
  if (found != std::string::npos)
  {
    return -1;
  }
  //data return a pointer to the start of the array of char *
  int portNum = atoi(port.data());
  if (portNum < 1024 || portNum > 65535)
  {
    return -1;
  }
  return portNum;
}
bool isValidDistance(std::string distance)
{
    return distance == "MIN" || distance == "MAN" || distance == "CHB" || distance == "AUC" || distance == "CAN";
}
// this function check if the input from the user is valid.
bool isValidDouble(std::string s)
{
    if (s.length() == 0)
    {
        return false;
    }
    // we want to get from the user only this characters "0123456789.-" as they represent Double number.
    std::size_t found = s.find_first_not_of("0123456789.-Ee");
    if (found != std::string::npos)
    {
        return false;
    }
    return true;
}
bool isValidVector(std::vector<string> vec)
{
    for (int i = 0; i < vec.size() - 2; i++)
    {
        if (!isValidDouble(vec[i]))
        {
            return false;
        }
    }
    return true;
}
std::vector<std::string> getUserInput(string input)
{
    if (input == "-1")
    {
        throw std::out_of_range("close the program");
    }
    std::vector<std::string> vec;
    // split the input into tokens every time in the line that "" is appering the token store the string before the "".
    std::string token;
    // read the data into the stringstream
    std::istringstream iss(input);
    // split by any '' (space key)
    while (std::getline(iss, token, ' '))
    {

        // insert the input into the vector.
        vec.push_back(token);
    }
    if (vec.size() < 3)
    {
        throw std::invalid_argument("Not Enough Arguments");
    }
    return vec;
}
std::string getUserDistance(vector<std::string> input)
{
    if (!isValidDistance(input[input.size() - 2]))
    {
        throw std::invalid_argument("Invalid Distance argument");
    }
    return input[input.size() - 2];
}
int getUserK(vector<std::string> input)
{
    std::size_t found = input[input.size() - 1].find_first_not_of("0123456789");
    if (found != std::string::npos)
    {
        throw std::invalid_argument("Invalid K argument");
    }
    int k = stoi(input[input.size() - 1]);
    if (k <= 0)
    {
        throw std::invalid_argument("Invalid K argument");
    }
    return k;
}
// this function get the input from the user and then insert the valid input into vector.
std::vector<double> getUserVector()
{
    std::string input;
    // getting all the line fromn the user.
    std::getline(std::cin, input);
    std::vector<double> vec;
    // split the input into tokens every time in the line that "" is appering the token store the string before the "".
    std::string token;
    // read the data into the stringstream
    std::istringstream iss(input);
    // split by any '' (space key)
    while (std::getline(iss, token, ' '))
    {
        // check if the input is valid
        if (!isValidDouble(token))
        {
            throw std::invalid_argument("Invalid arguments for the Vector");
        }
        // insert the input into the vector.
        vec.push_back(std::stod(token));
    }
    return vec;
}

int main(int argc, char *argv[])
{



    Classifier cl;
    ifstream infile;
    try
    {
        infile.open("datasets/iris/iris_classified.csv");
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
    }
    // get the data from the file
    cl.getClassifiedVectors(infile);
    infile.close();


    const int port_no =getPort(string(argv[2]));
  if (port_no < 0)
  {
    cout << "invalid input" << endl;
    return -1;
  }
    const int server_port = 12347;
    // socket creation,SOCK_STREAM is a const for TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;            // struct for address
    memset(&sin, 0, sizeof(sin));      // reset the struct
    sin.sin_family = AF_INET;          // address protocol type
    sin.sin_addr.s_addr = INADDR_ANY;  // const for any address
    sin.sin_port = htons(server_port); // define the port
    // binding the socket with bind command and checking if bind could be done
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0)
    { // listen to up to 5 clients at a time
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin; // create a address struct for the sender information
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *)&client_sin,
                             &addr_len); // accept command creates a new socket for the client that wanted to connect.
    if (client_sock < 0)
    { // check if the creation of socket for client failed
        perror("error accepting client");
    }
    while (true)
    {
        char buffer[4096] = {0};                                          // create a buffer for the client
        int expected_data_len = sizeof(buffer);                           // the maximum length of data to recieve
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0); // recieve a message from the clients socket into the buffer. 
        if (read_bytes == 0)
        {
            // connection is closed
        }
        else if (read_bytes < 0)
        {
            // error
        }
        else
        {
            string input(buffer);
            std::string distance;
            int k;
            vector<string> userInput;
            try
            {
                userInput = getUserInput(input);
            }
            catch (std::out_of_range e)
            {
                close(sock);
                break;
            }
            catch (exception e)
            {
                cout << "Not Enough Arguments" << endl;
                continue;
            }
            try
            {
                k = getUserK(userInput);
            }
            catch (exception e)
            {
                cout << "Invalid K argument" << std::endl;
                continue;
            }
            try
            {
                distance = getUserDistance(userInput);
            }
            catch (exception e)
            {
                cout << "Invalid Distance argument" << std::endl;
                continue;
            }

            if (!isValidVector(userInput))
            {
                cout << "Invalid Argument For The Vector";
                continue;
            }
            vector<double> vec;
            for (int i = 0; i < userInput.size() - 2; i++)
            {
                // insert the input into the vector.
                vec.push_back(std::stod(userInput[i]));
            }
            string answer;
            try
            {
                // get the answer in s
                answer = cl.Classify(vec, k, distance);
            }
            catch (exception e)
            {
                std::cout << "Invalid Vector To Classify" << std::endl;
            }

            int sent_bytes = send(client_sock, answer.data(), answer.size(), 0);
            if (sent_bytes < 0)
            {
                perror("error sending to client");
            }
        }
    }

    close(sock);
    return 0;
}