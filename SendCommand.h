<<<<<<< HEAD:SendCommand.h
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
=======

#ifndef SENDCOMMAND_H
#define SENDCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
// the is for the 5th method in the switch case.
class SendCommand : public Command
{
public:
    SendCommand(CLI &cli, DefaultIO &dio);
    virtual void execute();
    ~SendCommand() = default;
};
#endif
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/SendCommand.h
