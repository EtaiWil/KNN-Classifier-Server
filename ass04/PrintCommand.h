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
