<<<<<<< HEAD:CLI.cpp

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
=======

// move it to here because there are 3 include dependencies between ClI class and the Command classes.
#include "CLI.h"
#include "UploadCommand.h"
#include "SettingCommand.h"
#include "ClassifyCommand.h"
#include "PrintCommand.h"
#include "SendCommand.h"
#include "ExitCommand.h"
// the constructor that creates  the CLI object.
CLI::CLI(DefaultIO &dio) : dio(dio), cl(Classifier()), testVectors(*(new list<tuple<vector<double>, string>>)), commands(getCommands(dio))
{
    // first setting initialization as instructed.
    this->k = 5;
    this->distanceMetric = "AUC";
}
// this method gets the trainvectros string and sends it as a stream to the Classifier.
void CLI::getTrainVectors(string s)
{
    std::istringstream is(s);
    cl.getClassifiedVectors(is);
}
// create all the Command Objects for the Menu
vector<Command *> &CLI::getCommands(DefaultIO &dio)
{
    vector<Command *> &commands = *(new vector<Command *>());
    commands.push_back(new UploadCommand(*(this), dio));
    commands.push_back(new SettingCommand(*(this), dio));
    commands.push_back(new ClassifyCommand(*(this), dio));
    commands.push_back(new PrintCommand(*(this), dio));
    commands.push_back(new SendCommand((*this), dio));
    commands.push_back(new ExitCommand((*this), dio));
    return commands;
}
// get the string of the test vectors and store them in the testVectors list.
void CLI::getTestVectors(string s)
{
    // convert the string to a stream
    std::istringstream is(s);
    string lineToken;
    // read line by line.
    while (getline(is, lineToken))
    {
        // ignore /r in the files.
        std::size_t found = lineToken.find("\r");
        if (found != std::string::npos)
        {
            lineToken = lineToken.substr(0, found);
        }
        // if the line is empty.
        if (lineToken.empty())
        {
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
        // push the vector into a tokens vector of strings
        while (std::getline(iss, token, ','))
        {
            tokens.push_back(token);
        }
        // check if all the tokens are valid doubles.
        for (int i = 0; i < tokens.size(); i++)
        {
            if (!isValidDouble(tokens[i]))
            {
                throw invalid_argument("Invalid arguments for the Vector");
            }
            // insert the input into the vector.
            get<0>(unclassifiedItem).push_back(stod(tokens[i]));
        }
        // the vector is unclassified so it's empty.
        get<1>(unclassifiedItem) = "";
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
// this functions creates a menu string from the Commands and writes it using the DefaultIO.
void CLI::displayMenu()
{
    string s = "";
    s.append("Welcome to the KNN Classifier Server. Please choose an option:\n");
    // create a menu from all the Commands.
    for (int i = 0; i < this->commands.size(); i++)
    {
        string index;
        if (i != 5)
        {
            index = std::to_string(i + 1);
        }
        else
        {
            index = std::to_string(i + 3);
        }
        s.append(index + ". " + commands[i]->getDesc() + "\n");
    }
    // delete the last line drop
    s.pop_back();
        // write the menu to the dio.
        this->dio.write(s);
}
// this method gets a menu option from the user.
int CLI::getMenuOption()
{
    // read an input from the DefaultIO
    string input;
    try
    {
        input = this->dio.read();
    } // if the read fails
    catch (exception &e)
    {
        return -2;
    }
    // try converting it to an integer
    int option;
    try
    {
        option = stoi(input);
    } // if conversion fails - > invalid argument.
    catch (std::invalid_argument e)
    {
        return -1;
    }
    // if the given option is 6,7,9 and above or a nonpositive int
    if (option == 6 || option == 7 || option > 8 || option < 1)
    {
        return -1;
    }
    else if (option == 8)
    {
        option = 6;
    }
    // decrease the option by one to be used as an index for the list
    option--;
    return option;
}
// this method is a loop that prints a menu, read an input from the user and if the input is valid it activated the matching command.
void CLI::start()
{
    int menuOption = 0;
    while (menuOption != 5)
    {
        this->displayMenu();
        menuOption = this->getMenuOption();
        if (menuOption == -1)
        { // invalid input from user;
            this->dio.write("invalid input");
        }
        //-2 means the socket fails
        else if (menuOption == -2)
        {
            break;
        }
        else
        {
            // try in order to catch socket fails.
            try
            {
                this->commands[menuOption]->execute();
            } // in case the socket fails
            catch (exception &e)
            {
                break;
            }
        }
    }
}
// getter for K member
int CLI::getK()
{
    return this->k;
}
// getter for Distance Metric member
string CLI::getDistanceMetric()
{
    return this->distanceMetric;
}
// setter for K member
void CLI::setK(int k)
{
    this->k = k;
}
// setter for Distance Metric Member
void CLI::setDistanceMetric(string distanceMetric)
{
    this->distanceMetric = distanceMetric;
}
// check if Test Vectors list is Empty.
bool CLI::isTestVectorsEmpty()
{
    return this->testVectors.empty();
}
// use the classifier to classify each one of the test Vectors.
void CLI::classifyTestVectors()
{
    for (auto &tVector : this->testVectors)
    {
        // classify using the classifier
        string classification = this->cl.Classify(get<0>(tVector), this->k, this->distanceMetric);
        // save classification in the testVectors list.
        get<1>(tVector) = classification;
    }
}
// this method returns a list that contains the results of the Test vectors Classifications.
string CLI::getTestClassifications()
{
    string s;
    int i = 1;
    // add the number of vector and his classification in the format "number 'tab' classification"
    for (auto &tVector : this->testVectors)
    {
        s.append(to_string(i++) + "\t" + get<1>(tVector) + "\n");
    }
    // remove the last line drop.
    s.pop_back();
    return s;
}
// returns true if all the test vectors are classified and false otherwise.
bool CLI::isTestVectorsClassified()
{
    for (auto &tVector : this->testVectors)
    {
        if (get<1>(tVector).empty())
        {
            return false;
        }
    }
    return true;
}
// check if the classifier is trained -> meaning he got any train vectors.
bool CLI::isClassifierTrained()
{
    return this->cl.isTrained();
}
// destructor
CLI::~CLI()
{
    reset();
}
// the reset is used by the destructor and delets all allocated data.
void CLI::reset()
{
    delete (&testVectors);
    for (auto obj : this->commands)
    {
        delete obj;
    }
    delete (&commands);
}
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/CLI.cpp
