#ifndef CLASSIFYCOMMAND_H
#define CLASSIFYCOMMAND_H
#include "CLI.h"
#include "Command.h"
using namespace std;
// drived from command class, this class is exacuting the third option in the menu.
class ClassifyCommand : public Command {
public:
//constructor.
    ClassifyCommand(CLI& cli,DefaultIO &dio);
    //this method excact classifing the data.
    virtual void execute();
    ~ClassifyCommand()=default;

};
#endif