#include "client.h"
Client::Client(DefaultIO& dio):dio(dio){
    this->isMenuPrinted=false;
}
bool Client::isPrintMenu() {
    return this->isMenuPrinted;
}
bool Client::checkMessageForMenu() {
    std::size_t loc = this->message.find("Welcome to the KNN Classifier Server.");
    if(loc!=std::string::npos){
        return true;
    }
    return false;
}
string Client::getMessage() {
    //if(this->message.empty()){
    this->readMessage();
    //}
    this->isMenuPrinted=this->checkMessageForMenu();
    string messageToReturn;
    messageToReturn.append(this->message);
    this->message.clear();
    return messageToReturn;
}
//if(this->checkMessageForMenu()){
  //  std::size_t loc = this->message.find("Welcome to the KNN Classifier Server.");
    //string messageToReturn = this->message.substr(0,loc);
    //this->message=this->message.substr(loc,this->message.size());
    //return messageToReturn;

//string messageToReturn = this->message;
//this->message="";
//return messageToReturn;
//}
void Client::readMessage(){
    this->message=dio.read();
}
/*
string Client::getMenu(){
    if(this->message.empty()){
        this->readMessage();
    }
    if(!this->checkMessageForMenu()){
        this->readMessage();
    }
        std::size_t loc = this->message.find("Welcome to the KNN Classifier Server.");
        string messageToReturn= this->message.substr(loc,this->message.size());
        this->message=this->message.substr(0,loc);
        return messageToReturn;

}
 */
void Client::writeMessage(string s) {
    this->dio.write(s);
}

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
void Client::uploadFiles(){
    string fileDir;
    cin>>fileDir;
    ifstream infile;
    try
    {
        // open the file
        infile.open(fileDir);
        //if file is invalid (non existing or locked)
        if(!infile.good())
        {
            infile.close();
            cout<<"invalid input"<<endl;
            //do it to give the server a message that ends in \n\n like we agreed
            this->writeMessage("ERRORABORT");
        }
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
        //do it to give the server a message that ends in \n\n like we agreed
        this->writeMessage("ERRORABORT");
    }
    // get the data from the file
    string data,line;
    while (getline(infile, line)&&(!line.empty())) {
        data.append(line+"\n");
    }
    infile.close();
    //end of data sign we agreed on.
    data.append("\n\n");
    this->writeMessage(data);
    data="";
    string message= this->getMessage();
    cout<<message<<endl;
    cin>>fileDir;
    try
    {
        // open the file
        infile.open(fileDir);
        //if file is invalid (non existing or locked)
        if(!infile.good())
        {
            infile.close();
            cout<<"invalid input"<<endl;
            //do it to give the server a message that ends in \n\n like we agreed
            this->writeMessage("ERRORABORT");
        }
    }
    catch (exception e)
    {
        cout << "problem opening file" << endl;
        //do it to give the server a message that ends in \n\n like we agreed
        this->writeMessage("ERRORABORT");
    }
    // get the data from the file
    while (getline(infile, line)&&(!line.empty())) {
        data.append(line+"\n");
    }
    infile.close();
    //end of data sign we agreed on.
    data.append("\n\n");
    this->writeMessage(data);
    string messageTwo=this->getMessage();
    cout<<messageTwo<<endl;
    //message=dio.read();
    //cout<<message<<endl;
}
string getMenuInput(){
    std::string input;
    // getting all the line from the user.
    cin>>input;
    return input;

}
void Client::algoSetting(string setting) {
    cout << setting << endl;
    string settingStr;
    //cin.clear();
    /*fflush(stdin);
    char c=0;
    while(c!='\n') {
        scanf("% c", &c);
        settingStr.push_back(c);
    }*/
    cin.ignore(INT16_MAX, '\n');
    std::getline(cin, settingStr);
    if (settingStr.empty() || settingStr == "\n") {
        this->writeMessage("NOCHANGE");
    }
    this->writeMessage(settingStr);
    string reply = this->getMessage();
    if (reply != "OKOK") {
        std::size_t loc = reply.find("OKOK");
        if (loc != std::string::npos) {
            reply = reply.substr(loc + 4, reply.size());
        }
        cout << reply;
    }
}
void Client::classify(){
    if(!this->isPrintMenu()){
        cout<<this->getMessage()<<endl;
    }
}
void Client::getClassification(){
    if(!this->isPrintMenu()){
        cout<<this->getMessage()<<endl;
    }
}
void getClassificationToFile(string data){

        try {
            std::ofstream file("ClassifiedVectors.txt");
            if (file.is_open()) {
                file << data;
                file.close();
                return;
            } else {
                std::cout << "invalid input"<<endl;
                return;
            }
        }
        catch (const std::exception e) {
            cout << "invalid input" << endl;
        }
    }



int main(int argc, char *argv[]) {
    // first is the name of the program second is the ip and third is the ip
    if (argc != 3) {
        cout << "invalid input" << endl;
        return -1;
    }
    // stote the prot number in Server_port  if the number is -1 its not valid otherwise valid.
    const int port_no = Client::getPort(string(argv[2]));
    if (port_no < 0) {
        cout << "invalid input" << endl;
        return -1;
    }
    // check if the if that given by the user is valid.
    if (!Client::isValidIpAddress(argv[1])) {
        cout << "invalid input" << endl;
        return -1;
    }
    // store the argument from the user now check if he is vaalid.
    const char *ip_address = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // if negative its mean that we did not succesed to create a socket.
    if (sock < 0) {
        perror("error creating socket");
        return -1;
    }
    struct sockaddr_in sin;                                      // struct for address
    memset(&sin, 0, sizeof(sin));                                // reset the struct
    sin.sin_family = AF_INET;                                    // address protocol type
    sin.sin_addr.s_addr = inet_addr(ip_address);                 // convert ip address to binary to create socket.
    sin.sin_port = htons(port_no);                               // convert port to network order bytes
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) // if connection to server fails
    {
        // print error message.
        perror("error connecting to server");
        // close socket
        close(sock);
        // close the program
        return -1;
    }
    SocketIO sio(sock);
    Client client(sio);

    int option = 0;
    //bool readSkip=false;
    while (option!=8) {
        if(!client.isPrintMenu()) {
            string s = client.getMessage();
            cout << s<<endl;
        }
        //cout.flush();
        //cin.clear();
        string input=getMenuInput();
        client.writeMessage(input);
        string s;
        try {
            s = client.getMessage();
        }catch(exception& e){
            close(sock);
            return 0;
        }
          if(input!="5"&&input!="2"&&input!="8"){
            cout<<s<<endl;
        }
      //  std::size_t loc = message.find("Welcome to the KNN Classifier Server.");
       // if(loc != std::string::npos) {
        //    readSkip = true;
       // }
        if(s == "invalid input"){
            cout<<s<<endl;
            continue;
        }
        option=stoi(input);

        switch (option) {
            case 1:
                client.uploadFiles();
                break;
            case 2: {
                //string message=client.getMessage();
                string setting;
                std::size_t loc = s.find("ENDOFSETTING");
                if (loc != std::string::npos) {
                    setting = s.substr(0, loc);
                    s = s.substr(loc + 12, s.size());
                    client.algoSetting(setting);
                    cout << s << endl;
                }
            }
                break;
            case 3:
                client.classify();
                break;
            case 4:
                client.getClassification();
                break;
            case 5: {
                std::size_t loc = s.find("please upload data");
                if (loc != std::string::npos) {
                cout<<s<<endl;
                continue;
                }
                loc = s.find("please classify the data");
                if (loc != std::string::npos) {
                cout<<s<<endl;
                continue;
                }
                //string message=client.getMessage();
                string classifications;
                loc = s.find("ENDOFCLASSIFICATION");
                if (loc != std::string::npos) {
                    classifications = s.substr(0, loc);
                    std::thread t(getClassificationToFile, classifications);
                    t.detach();
                    //s = s.substr(loc + 19, classifications.size());
                    s = s.substr(loc + 19, s.size());
                    cout<<s<<endl;
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
