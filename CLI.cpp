
//move it to here because there are 3 implementation dependency between cli class uplodadcommand c command.
#include "CLI.h"
#include "UploadCommand.h"
#include "SettingCommand.h"
#include "ClassifyCommand.h"
#include "PrintCommand.h"
#include "SendCommand.h"
#include "ExitCommand.h"

CLI::CLI(DefaultIO& dio):dio(dio),cl(Classifier()),testVectors(*(new list<tuple<vector<double>, string>>)),commands(getCommands(dio)){
    this->k=5;
    this->distanceMetric="AUC";
}
void CLI::getTrainVectors(string s){
    std::istringstream is(s);
    cl.getClassifiedVectors(is);
    int x=3;
}
vector<Command*>& CLI::getCommands(DefaultIO& dio){
    vector<Command*> &commands=*(new vector<Command*>());
    commands.push_back(new UploadCommand(*(this),dio));
    commands.push_back(new SettingCommand(*(this),dio));
    commands.push_back(new ClassifyCommand(*(this),dio));
     commands.push_back(new PrintCommand(*(this),dio));
     commands.push_back(new SendCommand((*this),dio));
    commands.push_back(new ExitCommand((*this),dio));
    return commands;
}
void CLI::getTestVectors(string s){
    std::istringstream is(s);
    string lineToken;
    while (getline(is, lineToken))
    {
        std::size_t found = lineToken.find("\r");
        if(found != std::string::npos) {
            lineToken = lineToken.substr(0, found);
        }
        if(lineToken.empty()){
            continue;
        }

        // getting all the line from the user.
        std::vector<double> vec;
        // split the input into tokens every time in the line that "" is appering the token store the string before the "".
        std::string token;
        // read the data into the stringstream
        std::istringstream iss(lineToken);
        tuple<vector<double>, string> unclassifiedItem;
        vector<string> tokens;
        // split by any ',' (',' key)
        while (std::getline(iss, token, ','))
        {
            tokens.push_back(token);
        }
        for(int i = 0; i < tokens.size(); i++)
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
void CLI::displayMenu(){
    string s="";
    s.append("Welcome to the KNN Classifier Server. Please choose an option:\n");
    for(int i=0;i<this->commands.size();i++){
        string index;
        if(i!=5){
            index=std::to_string(i+1);
        }else{
            index=std::to_string(i+3);
        }
        s.append(index+". "+commands[i]->getDesc()+"\n");
    }
    this->dio.write(s);
}
int CLI::getMenuOption(){
    string input=this->dio.read();
    int option;
    try {
        option = stoi(input);
    }catch(std::invalid_argument e){
        return -1;
    }
    if(option == 6 || option ==7 || option > 8){
        return -1;
    }
    else if(option==8){
        option=6;
    }
    option--;
    return option;
}
void CLI::start(){
    int menuOption=0;
    while(menuOption!=5){
        this->displayMenu();
        menuOption=this->getMenuOption();
        if(menuOption == -1){ //invalid input from user;
            this->dio.write("invalid input");
        }
        this->commands[menuOption]->execute();
    }


}
int CLI::getK(){
    return this->k;
}
string CLI::getDistanceMetric(){
return this->distanceMetric;;
}
void CLI::setK(int k){
  this->k=k;
}
void CLI::setDistanceMetric(string distanceMetric){
this->distanceMetric=distanceMetric;
}
bool CLI::isTestVectorsEmpty(){
    return this->testVectors.empty();
}
void CLI::classifyTestVectors(){
    for (auto &tVector: this->testVectors) {
        string classification = this->cl.Classify(get<0>(tVector), this->k, this->distanceMetric);
        get<1>(tVector) = classification;
    }
}
string CLI::getTestClassifications(){
    string s;
    int i=1;
    for(auto& tVector:this->testVectors) {
           s.append(to_string(i++)+"\t"+get<1>(tVector)+"\n");
        }
    s.pop_back();
    return s;
}
bool CLI::isTestVectorsClassified(){
    for(auto& tVector:this->testVectors) {
        if(get<1>(tVector).empty()){
            return false;
        }
    }
    return true;
}
bool CLI::isClassifierTrained(){
    return this->cl.isTrained();
}
CLI::~CLI(){
        reset();

}
void CLI::reset(){
    delete (&testVectors);
    for(auto obj : this->commands) {
        delete obj;
    }
    delete(&commands);


}
