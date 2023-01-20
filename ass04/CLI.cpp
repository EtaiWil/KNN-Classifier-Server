
//move it to here because there are 3 implementation dependency between cli class uplodadcommand c command.
#include "CLI.h"
#include "UploadCommand.h"


CLI::CLI(DefaultIO& dio):dio(dio),cl(Classifier()),testVectors(*(new list<tuple<vector<double>, string>>)),commands(getCommands()){}
void CLI::getTrainVectors(string s){
    std::istringstream is(s);
    cl.getClassifiedVectors(is);
}
vector<Command*>& CLI::getCommands(){
    vector<Command*> &commands=*(new vector<Command*>());
    commands.push_back(new UploadCommand(*(this),std::string("upload an unclassified csv data file"),dio));
    return commands;
}
void CLI::getTestVectors(string s){
    std::istringstream is(s);
    string token;
    while (getline(is, token))
    {
        // getting all the line fromn the user.
        std::vector<double> vec;
        // split the input into tokens every time in the line that "" is appering the token store the string before the "".
        std::string token;
        // read the data into the stringstream
        std::istringstream iss(s);
        tuple<vector<double>, string> unclassifiedItem;
        vector<string> tokens;
        // split by any ',' (',' key)
        while (std::getline(iss, token, ','))
        {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size(); i++)
        {
            if (!isValidDouble(tokens[i]))
            {
                throw invalid_argument("Invalid arguments for the Vector");
            }
            // insert the input into the vector.
            get<0>(unclassifiedItem).push_back(stod(tokens[i]));
        }
        get<1>(unclassifiedItem) ="";
        this->testVectors.push_back(unclassifiedItem);
    }

}
// this function check if the input from the user is valid.
bool CLI::isValidDouble(string s)
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
void CLI::start(){
    this->dio.write("Welcome to the KNN Classifier Server. Please choose an option:");
    for(int i=0;i<this->commands.size();i++){
        string index=std::to_string(i+1);
        string s=index+commands[i]->getDesc();
        this->dio.write(s);
    }
    string input=this->dio.read();
    int option=atoi(input.data());
    this->commands[option-1]->execute();

}
