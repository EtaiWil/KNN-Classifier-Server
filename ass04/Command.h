#ifndef COMMAND_H_
#define COMMAND_H_

#include "DefaultIO.h"
#include "CLI.h"
#include <string>
class CLI;

using namespace std;
class Command{
protected:
string description;
DefaultIO& dio;
CLI& cli;
public:
    Command(CLI& cli,string desription,DefaultIO &dio);
    string getDesc();
    virtual void execute()=0;

};
#endif