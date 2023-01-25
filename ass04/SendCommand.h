
#ifndef SENDCOMMAND_H
#define SENDCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
//the is for the 5th method in the switch case.
class SendCommand : public Command {
public:
    SendCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~SendCommand()=default;

};
#endif
