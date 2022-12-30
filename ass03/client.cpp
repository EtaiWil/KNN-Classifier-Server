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
using namespace std;

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
int main()
{
  const char *ip_address = "127.0.0.1";
  const int port_no = 12345;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
    perror("error creating socket");
  }
  struct sockaddr_in sin;
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(ip_address);
  sin.sin_port = htons(port_no);
  if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
  {
    perror("error connecting to server");
  }
  while (true)
  {
    std::string input;
    // getting all the line fromn the user.
    std::getline(std::cin, input);
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
      break;
    }
     if (!isValidVector(userInput))
        {
            cout << "Invalid Argument For The Vector";
            continue;
        }

    try
    {
      k = getUserK(userInput);
    }
    catch (exception e)
    {
      cout << "Invalid K argument" << std::endl;
      break;
    }
    try
    {
      distance = getUserDistance(userInput);
    }
    catch (exception e)
    {
      cout << "Invalid Distance argument" << std::endl;
      break;
    }

    int data_len = input.size();
    int sent_bytes = send(sock, input.data(), data_len, 0);
    if (sent_bytes < 0)
    {
      // error
    }
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
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
      cout << buffer<<endl;
    }

    // cout<<"k= "<<k<<" distance = "<<distance<<endl;

    /*
            const char* ip_address = "127.0.0.1";
            const int port_no = 5555;
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
            perror("error creating socket");
            }
            struct sockaddr_in sin;
            memset(&sin, 0, sizeof(sin));
            sin.sin_family = AF_INET;
            sin.sin_addr.s_addr = inet_addr(ip_address);
            sin.sin_port = htons(port_no);
            if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server");
            }
            char data_addr[] = "Im a message";
            int data_len = strlen(data_addr);
            int sent_bytes = send(sock, data_addr, data_len, 0);
            if (sent_bytes < 0) {
            // error
            }
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
            // connection is closed
            }
            else if (read_bytes < 0) {
            // error
            }
            else {
            cout << buffer; }
            close(sock);
            return 0;
            */
  }
  return 0;
}
