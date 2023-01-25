#ifndef UPLOADCOMMAND_H
#define UPLOADCOMMAND_H
#include <string>
#include "CLI.h"
#include "Command.h"
using namespace std;
//this is for the first switch case in the client.
class UploadCommand : public Command {
    public:
    UploadCommand(CLI& cli,DefaultIO &dio);
    //upload the csv classifed data and the unclassifed data.
    virtual void execute();
    ~UploadCommand()=default;

};
#endif