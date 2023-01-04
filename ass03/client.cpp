#include "client.h"

bool Client::isValidIpAddress(char *ipAddress)
{ // use the inet_pton routine to check if the ip address is valid.
  struct sockaddr_in sa;
  // if the address is valid reslut will get 1 value.
  int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
  // will return true if ip is valid.
  return (result == 1);
}

// if port is invalid returs -1,otherwise returns the port number as int
int Client::getPort(string port)
{
  // look for a non integer char in the port string
  std::size_t found = port.find_first_not_of("0123456789");
  if (found != std::string::npos) // if found return -1
  {
    return -1;
  }
  // data return a pointer to the start of the array of char *
  int portNum = atoi(port.data()); // convert the port into int (can because of first check)
  if (portNum < 1024 || portNum > 65535)
  {
    return -1;
  }
  return portNum;
}
// check if the string is one of the valid distances.
bool Client::isValidDistance(std::string distance)
{
  return distance == "MIN" || distance == "MAN" || distance == "CHB" || distance == "AUC" || distance == "CAN";
}
// check if the char is dot.
bool Client::isDot(char c)
{
  if (c == '.')
    return true;
  else
    return false;
}
// this function check if the input from the user is valid.
bool Client::isValidDouble(std::string s)
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
  // if ther is more then one dot in a string it can not represent a vector so it is not valid.
  size_t count = std::count_if(s.begin(), s.end(), isDot);
  if (count > 1)
  {
    return false;
  }
  // if the last char in the string is dot its mean that the input is not valide example "1."

  if (s.back() == '.')
  {
    return false;
  }
  return true;
}
// if the user enterd -1 we need to finish the program.
std::vector<std::string> Client::getUserInput(string input)
{
  // if inserted -1 we need to finish the program.
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
  // if the input is too small
  if (vec.size() < 3)
  {
    throw std::invalid_argument("Not Enough Arguments");
  }
  return vec;
}
// check here if the input distance by the user is valid.
std::string Client::getUserDistance(vector<std::string> input)
{
  if (!isValidDistance(input[input.size() - 2]))
  {
    throw std::invalid_argument("Invalid Distance argument");
  }
  return input[input.size() - 2];
}
// check if the k given by the user if valid.
int Client::getUserK(vector<std::string> input)
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
std::vector<double> Client::getUserVector()
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
// check the inputs to see if one contains invalid double.
bool Client::isValidVector(std::vector<string> vec)
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

int main(int argc, char *argv[])
{
  // first is the name of the program second is the ip and third is the ip
  if (argc != 3)
  {
    cout << "invalid input" << endl;
    return -1;
  }
  // stote the prot number in Server_port  if the number is -1 its not valid otherwise valid.
  const int port_no = Client::getPort(string(argv[2]));
  if (port_no < 0)
  {
    cout << "invalid input" << endl;
    return -1;
  }
  // check if the if that given by the user is valid.
  if (!Client::isValidIpAddress(argv[1]))
  {
    cout << "invalid input" << endl;
    return -1;
  }
  // store the argument from the user now check if he is vaalid.
  const char *ip_address = argv[1];
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  // if negative its mean that we did not succesed to create a socket.
  if (sock < 0)
  {
    perror("error creating socket");
    return -1;
  }
  struct sockaddr_in sin;                                      // struct for address
  memset(&sin, 0, sizeof(sin));                                // reset the struct
  sin.sin_family = AF_INET;                                    // address protocol type
  sin.sin_addr.s_addr = inet_addr(ip_address);                 // convert ip address to binary to create socket.
  sin.sin_port = htons(port_no);                               // convert port to network order bytes
  if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) // if connection to server fails
  {
    // print error message.
    perror("error connecting to server");
    // close socket
    close(sock);
    // close the program
    return -1;
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
      // get the user input in a vector (seperated by spaces).
      userInput = Client::getUserInput(input);
    }
    catch (std::out_of_range e) // if -1 is inserted by the user
    {
      close(sock); // close the connection with the server
      // close the
      break;
    }
    catch (exception e) // if the user did not give enough data (missing at least one argument for vector)
    {
      cout << "invalid input" << endl;
      // move to the next input from the user.
      continue;
    }
    if (!Client::isValidVector(userInput)) // if the user inserted an invalid vector (numbers)
    {
      cout << "invalid input" << endl;
      // move to the next input from the user.
      continue;
    }

    try
    {
      // get the K from the user input vector
      k = Client::getUserK(userInput);
    }
    catch (exception e) // if the K is invalid
    {
      cout << "invalid input" << std::endl;
      // move to the next input from the user.
      continue;
    }
    try
    {
      // get the distance metric from the user
      distance = Client::getUserDistance(userInput);
    }
    catch (exception e) // if the distance metric is invalid
    {
      cout << "invalid input" << std::endl;
      // move to the next input from the user.
      continue;
    }
    // length of the message
    int data_len = input.size();
    // send the given input to the user.
    int sent_bytes = send(sock, input.data(), data_len, 0);
    if (sent_bytes < 0) // if sending the message fails.
    {
      perror("error sending to server..");
      // move to the next input from the user.
      continue;
    }
    // buffer for server messages.
    char buffer[4096] = {0};
    // maximum excpected message size from the server
    int expected_data_len = sizeof(buffer);
    // get message from the server using the recv function.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) // if the connection is closed.
    {
      // close the socket.
      close(sock);
      // close the program.
      return 0;
    }
    else if (read_bytes < 0) // if receiving the message failds
    {
      // print error message
      perror("error recieving from server...");
      // close the connection
      close(sock);
      // close the program
      return -1;
    }

    else
    {
      // print the message from the server.
      cout << buffer << endl;
    }
  }
  // end the program
  return 0;
}
