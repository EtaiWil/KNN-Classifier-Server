<<<<<<< HEAD:PrintCommand.h
#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
class PrintCommand : public Command {
public:
    PrintCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~PrintCommand()=default;
};
#endif
=======
#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
// this class is for the fourth option in the switch case.
class PrintCommand : public Command
{
public:
    // constractor.
    PrintCommand(CLI &cli, DefaultIO &dio);
    virtual void execute();
    ~PrintCommand() = default;
};
#endif
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/PrintCommand.h
