#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
//this class is for the fourth option in the switch case.
class PrintCommand : public Command {
public:
//constractor.
    PrintCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~PrintCommand()=default;
};
#endif
