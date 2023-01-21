//
// Created by uziam on 21/01/2023.
//

#ifndef SENDCOMMAND_H
#define SENDCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
class SendCommand : public Command {
public:
    SendCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~SendCommand()=default;

};
#endif
