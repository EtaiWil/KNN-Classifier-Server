#ifndef COMMAND_H_
#define COMMAND_H_

#include "DefaultIO.h"
#include "CLI.h"
#include <string>
class CLI;
using namespace std;
//this class is the "father" of all comends. note that the execute of the command is pure virtual and every derived class will make a differnce excute 
class Command{
protected:
string description;
DefaultIO& dio;
CLI& cli;
public:
//constractor.
    Command(CLI& cli,string description,DefaultIO &dio);
    //return the description of the command.
    string getDesc();
    virtual void execute()=0;
    ~Command()=default;

};
#endif