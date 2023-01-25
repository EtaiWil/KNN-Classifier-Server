#include "client.h"
// constructor
Client::Client(DefaultIO &dio) : dio(dio)
{
    this->isMenuPrinted = false;
}
// returns the flag state to know if the menu was already printed.
bool Client::isPrintMenu()
{
    return this->isMenuPrinted;
}
// check if there is a menu in the message
bool Client::checkMessageForMenu()
{
    std::size_t loc = this->message.find("Welcome to the KNN Classifier Server.");
    if (loc != std::string::npos)
    {
        return true;
    }
    return false;
}
// get a message from the server and set the flag of the menu to know if the menu was already sent.
string Client::getMessage()
{
    this->readMessage();
    this->isMenuPrinted = this->checkMessageForMenu();
    string messageToReturn;
    messageToReturn.append(this->message);
    this->message.clear();
    return messageToReturn;
}
// read a message using the DefaultIO
void Client::readMessage()
{
    this->message = dio.read();
}
// write a Message using the DefaultIO
void Client::writeMessage(string s)
{
    this->dio.write(s);
}
// check for ip validity using inet_pton
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
// create a function that checks if the menu is in the message, and if so, it returns true;
void Client::uploadFiles()
{
    string fileDir;
    cin >> fileDir;
    ifstream infile;
    try
    {
        // open the file
        infile.open(fileDir);
        // if file is invalid (non existing or locked)
        if (!infile.good())
        {
            infile.close();
            cout << "invalid input" << endl;
            // do it to give the server a message that ends in \n\n like we agreed
            this->writeMessage("ERRORABORT");
        }
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
        // do it to give the server a message that ends in \n\n like we agreed
        this->writeMessage("ERRORABORT");
    }
    // get the data from the file
    string data, line;
    while (getline(infile, line) && (!line.empty()))
    {
        data.append(line + "\n");
    }
    infile.close();
    // end of data sign we agreed on.
    data.append("\n\n");
    this->writeMessage(data);
    data = "";
    string message = this->getMessage();
    cout << message << endl;
    cin >> fileDir;
    try
    {
        // open the file
        infile.open(fileDir);
        // if file is invalid (non existing or locked)
        if (!infile.good())
        {
            infile.close();
            cout << "invalid input" << endl;
            // do it to give the server a message that ends in \n\n like we agreed
            this->writeMessage("ERRORABORT");
        }
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
        // do it to give the server a message that ends in \n\n like we agreed
        this->writeMessage("ERRORABORT");
    }
    // get the data from the file
    while (getline(infile, line) && (!line.empty()))
    {
        data.append(line + "\n");
    }
    infile.close();
    // end of data sign we agreed on.
    data.append("\n\n");
    this->writeMessage(data);
    string messageTwo = this->getMessage();
    cout << messageTwo << endl;
    // message=dio.read();
    // cout<<message<<endl;
}
string getMenuInput()
{
    std::string input;
    // getting all the line from the user.
    cin >> input;
    return input;
}
void Client::algoSetting(string setting)
{
    // print the given setting
    cout << setting << endl;
    string settingStr;
    cin.ignore(INT16_MAX, '\n');
    // get an empty / nonempty line from the user
    std::getline(cin, settingStr);
    // if the user pressed enter, he didn't want to change the settings.
    if (settingStr.empty() || settingStr == "\n")
    {
        this->writeMessage("NOCHANGE");
    }
    // if he didnt press enter he wanted to change the settings.
    this->writeMessage(settingStr);
    // get the approval of change message from the server
    string reply = this->getMessage();
    if (reply != "OKOK")
    {
        std::size_t loc = reply.find("OKOK");
        if (loc != std::string::npos)
        {
            reply = reply.substr(loc + 4, reply.size());
        }
        cout << reply;
    }
}
// requst the server to classify the data
void Client::classify()
{
    if (!this->isPrintMenu())
    {
        cout << this->getMessage() << endl;
    }
}
// requst the server to send the classified results
void Client::getClassification()
{
    if (!this->isPrintMenu())
    {
        cout << this->getMessage() << endl;
    }
}
// requst the server to send the classified results and put them in a file.
void Client::getClassificationToFile(string data, ofstream &&file)
{

    file << data;
    file.close();
    return;
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
    // create a SocketIO object
    SocketIO sio(sock);
    // create a client object.
    Client client(sio);

    int option = 0;
    while (option != 8)
    { // while the user doesnt insert 8
        if (!client.isPrintMenu())
        {                                   // check if the menu was already printed
            string s = client.getMessage(); // if not get a message and print it
            cout << s << endl;
        }

        string input = getMenuInput(); // get an input from the user
        client.writeMessage(input);    // send it to the server
        string s;                      // try getting a message from the client
        try
        {
            s = client.getMessage(); // try getting a message from the client
        }
        catch (exception &e)
        { // if there was an error getting a message
            close(sock);
            return 0;
        }
        if (input != "5" && input != "2" && input != "8")
        { // if there is more to do in the chosen option
            cout << s << endl;
        }
        if (s == "invalid input")
        { // if the input was invalid
            cout << s << endl;
            continue; // continue to another iteration
        }
        option = stoi(input); // convert the input and activate the matching casse

        switch (option)
        {
        case 1:
            client.uploadFiles();
            break;
        case 2:
        {
            string setting;
            // check if the flag of ending the setting string is pressent.
            std::size_t loc = s.find("ENDOFSETTING");
            if (loc != std::string::npos)
            {
                setting = s.substr(0, loc);
                s = s.substr(loc + 12, s.size());
                // call the algosetting function
                client.algoSetting(setting);
                cout << s << endl;
            }
        }
        break;
        case 3:
            client.classify(); // call the classify function
            break;
        case 4:
            client.getClassification(); // call the get classification function
            break;
        case 5:
        {
            // if no data was sent
            std::size_t loc = s.find("please upload data");
            if (loc != std::string::npos)
            {
                cout << s << endl;
                continue;
            }
            // if the data was not classified.
            loc = s.find("please classify the data");
            if (loc != std::string::npos)
            {
                cout << s << endl;
                continue;
            }
            // if the server requsted us to open a file
            loc = s.find("OPENFILE");
            if (loc != std::string::npos)
            {
                // get directory for file
                string fileDir;
                cout << "Please enter a path to download results file" << endl;
                cin >> fileDir;

                try
                { // try openning file
                    fileDir.append("/ClassifiedVectors.txt");
                    std::ofstream file = ofstream(fileDir);
                    // if succeded
                    if (file.is_open())
                    {
                        // let the server know he can start sending the data
                        client.writeMessage("STARTSEND");
                        // get the data
                        string message = client.getMessage();
                        string classifications;
                        // find the end of data
                        loc = message.find("ENDOFCLASSIFICATION");
                        if (loc != std::string::npos)
                        {
                            classifications = message.substr(0, loc); // seoerate the classifications only
                            // create a thread to write the classifications to the file
                            std::thread t(Client::getClassificationToFile, classifications, std::move(file));
                            t.detach();
                            // get the rest of the message that was sent and print it.
                            message = message.substr(loc + 19, message.size());
                            cout << message << endl;
                        }
                        // if an error occured let the server know
                    }
                    else
                    {
                        client.writeMessage("ERROROPEN");
                        std::cout << "invalid input" << endl;
                        continue;
                    }
                } // if an error occured let the server know
                catch (exception &e)
                {
                    client.writeMessage("ERROROPEN");
                    cout << "invalid input" << endl;
                    continue;
                }
            }
        }
        break;

        case 8:
            close(sock);
            return 0;
            break;
        default:
            close(sock);
            return -1;
            break;
        }
    }

    // end the program
    return 0;
}
