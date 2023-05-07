<<<<<<< HEAD:Command.h
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
    Command(CLI& cli,string description,DefaultIO &dio);
    string getDesc();
    virtual void execute()=0;
    ~Command()=default;

};
=======
#ifndef COMMAND_H_
#define COMMAND_H_

#include "DefaultIO.h"
#include "CLI.h"
#include <string>
class CLI;
using namespace std;
// this class is the "father" of all comends. note that the execute of the command is pure virtual and every derived class will make a differnce excute
class Command
{
protected:
    string description;
    DefaultIO &dio;
    CLI &cli;

public:
    // constractor.
    Command(CLI &cli, string description, DefaultIO &dio);
    // return the description of the command.
    string getDesc();
    virtual void execute() = 0;
    ~Command() = default;
};
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/Command.h
#endif