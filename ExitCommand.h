<<<<<<< HEAD:ExitCommand.h
#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
class ExitCommand : public Command {
public:
    ExitCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~ExitCommand()=default;

};
#endif
=======
#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
class ExitCommand : public Command
{
public:
    // constractor.
    ExitCommand(CLI &cli, DefaultIO &dio);
    virtual void execute();
    ~ExitCommand() = default;
};
#endif
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/ExitCommand.h
