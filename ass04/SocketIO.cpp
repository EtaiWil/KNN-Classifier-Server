#include "SocketIO.h"
SocketIO::SocketIO(int sock):sock(sock){}
std::string SocketIO::read()
{
    char buffer[4096] = {0};                                          // create a buffer for the client
    int expected_data_len = sizeof(buffer);                           // the maximum length of data to recieve
    int read_bytes = recv(this->sock, buffer, expected_data_len, 0); // recieve a message from the clients socket into the buffer.
    if(read_bytes == 0){
        //perror("connection closed");
        close(this->sock);
        throw invalid_argument("Socket is disconnected");
        return "";
    }
    else if (read_bytes < 0)
    {
        //perror("connection error");
        close(this->sock);
        return "";
    }
    else
    {
        return string(buffer);
    }
}
void SocketIO::write(std::string s){
    int sent_bytes = send(this->sock, s.data(), s.size(), 0);
    // if message send fails.
    if (sent_bytes < 0)
    {
    perror("unable to send message to client");
    }

}
