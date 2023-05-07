<<<<<<< HEAD:server.cpp
#include "server.h"
void Server::sendErrorMessage(int sock)
{
    // create a string that contains the invalid input message
    string message = "invalid input";
    // send the message via the socket.
    int sent_bytes = send(sock, message.data(), message.size(), 0);
}
// if port is invalid returs -1,otherwise returns the port number as int
int Server::getPort(string port)
{
    // check if the port contains only this leeters. if its not, it is not valid port.
    std::size_t found = port.find_first_not_of("0123456789");
    if (found != std::string::npos)
    {
        return -1;
    }
    // data return a pointer to the start of the array of char *
    int portNum = atoi(port.data());
    // check if the nubmer of the port is valid. if get into the if condition its mean that the port number is not val.d
    if (portNum < 1024 || portNum > 65535)
    {
        return -1;
    }
    return portNum;
}
// check if the string is one of the valid distances.
bool Server::isValidDistance(std::string distance)
{
    return distance == "MIN" || distance == "MAN" || distance == "CHB" || distance == "AUC" || distance == "CAN";
}
bool Server::isDot(char c)
{
    if (c == '.')
        return true;
    else
        return false;
}

// this function check if the input from the user is valid.
bool Server::isValidDouble(std::string s)
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
// cheeck if every elemnt is valid vector by calling the function isValidDouble to check that the input is only dobule.
bool Server::isValidVector(std::vector<string> vec)
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
// if the user enterd -1 we need to finish the program.
std::vector<std::string> Server::getUserInput(string input)
{
    if (input == "-1")
    {
        throw std::out_of_range("close the program");
    }
    std::vector<std::string> vec;
    // split the input into tokens every time in the line that "" is appering the token store the string before the "".
    std::string token;
    // read the data into the string stream
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
std::string Server::getUserDistance(vector<std::string> input)
{
    if (!isValidDistance(input[input.size() - 2]))
    {
        throw std::invalid_argument("Invalid Distance argument");
    }
    return input[input.size() - 2];
}
// check here if the input "k" by the user is valid it is only valid if its contain only digits
int Server::getUserK(vector<std::string> input)
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
std::vector<double> Server::getUserVector()
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
void handleClient(int sock){
    SocketIO sio(sock);
    CLI cli(sio);
    cli.start();
    close(sock);
}
int main(int argc, char *argv[])
{

    // first is the name of the program second is the path to the dataset and third is the port

    if (argc != 2)
    {
        cout << "invalid input" << endl;
        return -1;
    }
    // stote the prot number in Server_port  if the number is -1 its not valid otherwise valid.
    const int Server_port = Server::getPort(string(argv[1]));
    //if the getPort returns -1 the port argument is invalid.
        if (Server_port < 0)
    {
        cout << "invalid input" << endl;
        //close the program (unable to run with given port)
        return -1;
    }
    // socket creation,SOCK_STREAM is a const for TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // error creating the socket.
    if (sock < 0)
    {
        perror("error creating socket");
        //close the program (unable to create the socket)
        return -1;
    }
    struct sockaddr_in sin;            // struct for address
    memset(&sin, 0, sizeof(sin));      // reset the struct
    sin.sin_family = AF_INET;          // address protocol type
    sin.sin_addr.s_addr = INADDR_ANY;  // const for any address
    sin.sin_port = htons(Server_port); // define the port
    // binding the socket with bind command and checking if bind could be done
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        return -1;
    }
    // listen to up to 5 clients at a time
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
    }
    while (true)
    {
        struct sockaddr_in client_sin; // create a address struct for the sender information
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len); // accept command creates a new socket for the client that wanted to connect.
        if (client_sock < 0)
        { // check if the creation of socket for client failed
            perror("error accepting client");
        }
        handleClient(client_sock);

    }
    // close the main socket that listens
    close(sock);
    // end the program (not happenning because the server is running nonstop).
    return 0;
=======
#include "server.h"
// if port is invalid returs -1,otherwise returns the port number as int
int Server::getPort(string port)
{
    // check if the port contains only this leeters. if its not, it is not valid port.
    std::size_t found = port.find_first_not_of("0123456789");
    if (found != std::string::npos)
    {
        return -1;
    }
    // data return a pointer to the start of the array of char *
    int portNum = atoi(port.data());
    // check if the nubmer of the port is valid. if get into the if condition its mean that the port number is not val.d
    if (portNum < 1024 || portNum > 65535)
    {
        return -1;
    }
    return portNum;
}
/// @brief handle a client from start to end
/// @param sock an open socket to the client
void handleClient(int sock)
{
    // create a socketIO object
    SocketIO sio(sock);
    // create a CLI object
    CLI cli(sio);
    // call the start method to handle the client
    cli.start();
    // afther done close the socket and finish.
    close(sock);
}
int main(int argc, char *argv[])
{

    // first is the name of the program second is the path to the dataset and third is the port

    if (argc != 2)
    {
        cout << "invalid input" << endl;
        return -1;
    }
    // stote the prot number in Server_port  if the number is -1 its not valid otherwise valid.
    const int Server_port = Server::getPort(string(argv[1]));
    // if the getPort returns -1 the port argument is invalid.
    if (Server_port < 0)
    {
        cout << "invalid input" << endl;
        // close the program (unable to run with given port)
        return -1;
    }
    // socket creation,SOCK_STREAM is a const for TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // error creating the socket.
    if (sock < 0)
    {
        perror("error creating socket");
        // close the program (unable to create the socket)
        return -1;
    }
    struct sockaddr_in sin;            // struct for address
    memset(&sin, 0, sizeof(sin));      // reset the struct
    sin.sin_family = AF_INET;          // address protocol type
    sin.sin_addr.s_addr = INADDR_ANY;  // const for any address
    sin.sin_port = htons(Server_port); // define the port
    // binding the socket with bind command and checking if bind could be done
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        return -1;
    }
    // listen to up to 5 clients at a time
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
    }
    while (true)
    {
        struct sockaddr_in client_sin; // create a address struct for the sender information
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len); // accept command creates a new socket for the client that wanted to connect.
        if (client_sock < 0)
        { // check if the creation of socket for client failed
            perror("error accepting client");
        }
        // create a thread for handling this client
        std::thread t(handleClient, client_sock);
        // detach thread from main thread.
        t.detach();
    }
    // close the main socket that listens
    close(sock);
    // end the program (not happenning because the server is running nonstop).
    return 0;
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/server.cpp
}