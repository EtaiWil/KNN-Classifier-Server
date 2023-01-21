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
#endif