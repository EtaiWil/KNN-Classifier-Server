<<<<<<< HEAD:ClassifyCommand.h
#ifndef CLASSIFYCOMMAND_H
#define CLASSIFYCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
class ClassifyCommand : public Command {
public:
    ClassifyCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~ClassifyCommand()=default;

};
=======
#ifndef CLASSIFYCOMMAND_H
#define CLASSIFYCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
// drived from command class, this class is exacuting the third option in the menu.
class ClassifyCommand : public Command
{
public:
    // constructor.
    ClassifyCommand(CLI &cli, DefaultIO &dio);
    // this method excact classifing the data.
    virtual void execute();
    ~ClassifyCommand() = default;
};
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/ClassifyCommand.h
#endif