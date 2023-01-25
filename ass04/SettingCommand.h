#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H
#include <string>
#include "CLI.h"
#include "Command.h"
using namespace std;
// use for the second option in the switch case in the client.
class SettingCommand : public Command
{
private:
    bool isValidDistance(std::string distance);

public:
    SettingCommand(CLI &cli, DefaultIO &dio);
    // changing the k and the mertic distance if needed.
    virtual void execute();
    ~SettingCommand() = default;
};
#endif