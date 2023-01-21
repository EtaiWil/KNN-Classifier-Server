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
