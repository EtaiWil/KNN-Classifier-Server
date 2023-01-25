#include "SendCommand.h"
SendCommand::SendCommand(CLI &cli, DefaultIO &dio) : Command(cli, "download results", dio) {}
// sending the classifcation of the data to the user.
void SendCommand::execute()
{
    if (!(this->cli.isClassifierTrained()) || this->cli.isTestVectorsEmpty())
    {
        this->dio.write("please upload data\n");
        return;
    }
    if (!this->cli.isTestVectorsClassified())
    {
        this->dio.write("please classify the data\n");
        return;
    }
    // tell the client to open a file
    this->dio.write("OPENFILE");
    string startSend = this->dio.read();
    // if the client sent us the send approval
    if (startSend == "STARTSEND")
    {
        this->dio.write(this->cli.getTestClassifications() + "ENDOFCLASSIFICATION"); // send the classifications and the symbol for the end.
    }
}