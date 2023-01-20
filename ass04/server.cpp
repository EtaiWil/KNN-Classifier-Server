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

int main(int argc, char *argv[])
{

    // first is the name of the program second is the path to the dataset and third is the port

    if (argc != 3)
    {
        cout << "invalid input" << endl;
        return -1;
    }

    Classifier cl;
    ifstream infile;
    try
    {
        // open the file
        infile.open(argv[1]);
        //if file is invalid (non existing or locked)
        if(!infile.good())
        {
            infile.close();
            cout<<"invalid input"<<endl;
            return -1;
        }
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
    }
    // get the data from the file
    cl.getClassifiedVectors(infile);
    infile.close();
    // stote the prot number in Server_port  if the number is -1 its not valid otherwise valid.
    const int Server_port = Server::getPort(string(argv[2]));
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
        while (true)
        {
            char buffer[4096] = {0};                                          // create a buffer for the client
            int expected_data_len = sizeof(buffer);                           // the maximum length of data to recieve
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0); // recieve a message from the clients socket into the buffer.
            if (read_bytes == 0)
            {
                // connection is closed
                close(client_sock);
                break;
            }
            else if (read_bytes < 0)
            {
                // error recieving message occured.
                continue;
            }
            else
            {
                string input(buffer);
                std::string distance;
                int k;
                vector<string> userInput;
                try
                {
                    // try to get input from the user
                    userInput = Server::getUserInput(input);
                }
                catch (exception e) // if getting the input from the user is invalid.
                {
                    Server::sendErrorMessage(client_sock);
                    // continue to get the next message from the client.
                    continue;
                }
                try
                {
                    // check if the given k is valid. if so get it in k.
                    k = Server::getUserK(userInput);
                }
                catch (exception e) // if the given k is invalid
                {
                    Server::sendErrorMessage(client_sock);
                    // continue to get the next message from the client.
                    continue;
                }
                try
                {
                    // get the distance metric into distance.
                    distance = Server::getUserDistance(userInput);
                }
                catch (exception e) // if the distance metric is not valid.
                {
                    Server::sendErrorMessage(client_sock);
                    // continue to get the next message from the client.
                    continue;
                }
                // check the inputs to see if one contains invalid double.
                if (!Server::isValidVector(userInput))
                {
                    Server::sendErrorMessage(client_sock);
                    // continue to get the next message from the client.
                    continue;
                }
                vector<double> vec;
                try
                {
                    for (int i = 0; i < userInput.size() - 2; i++) // all the strings without the distance metric and the k.
                    {
                        // insert the input into the vector.
                        vec.push_back(std::stod(userInput[i]));
                    }
                }
                catch (exception e) // if stod throws exception - invalid vector input.
                {
                    Server::sendErrorMessage(client_sock);
                    continue;
                }
                string answer;
                try
                {
                    // get the answer for the classification
                    answer = cl.Classify(vec, k, distance);
                }
                catch (exception e)
                {
                    // if the classification proccess fails
                    Server::sendErrorMessage(client_sock);
                    // send a message and continue to the next message the client sends.
                    continue;
                }

                int sent_bytes = send(client_sock, answer.data(), answer.size(), 0);
                // if message send fails.
                if (sent_bytes < 0)
                {
                    // print the error message
                    perror("error sending to client");
                    // close the connection to the client.
                    close(client_sock);
                    // move over to accept the next client.
                    break;
                }
            }
        }
    }
    // close the main socket that listens
    close(sock);
    // end the program (not happenning because the server is running nonstop).
    return 0;
}