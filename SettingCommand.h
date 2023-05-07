#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H
#include <string>
#include "CLI.h"
#include "Command.h"
using namespace std;
class SettingCommand : public Command {
private:
    bool isValidDistance(std::string distance);
public:
    SettingCommand(CLI& cli,DefaultIO &dio);
    virtual void execute();
    ~SettingCommand()=default;

};
#endif