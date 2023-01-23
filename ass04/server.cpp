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
        std::thread t(handleClient, client_sock);
        t.detach();

    }
    // close the main socket that listens
    close(sock);
    // end the program (not happenning because the server is running nonstop).
    return 0;
}