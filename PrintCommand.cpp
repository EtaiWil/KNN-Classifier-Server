<<<<<<< HEAD:PrintCommand.cpp
#include "PrintCommand.h"
PrintCommand::PrintCommand(CLI& cli,DefaultIO &dio):Command(cli,"display results",dio){}
void PrintCommand::execute() {
    if(!(this->cli.isClassifierTrained())||this->cli.isTestVectorsEmpty()){
        this->dio.write("please upload data");
        return;
    }
    if(!this->cli.isTestVectorsClassified()){
        this->dio.write("please classify the data");
        return;
    }
    this->dio.write(this->cli.getTestClassifications()+"\ndone\n");

=======
#include "PrintCommand.h"
PrintCommand::PrintCommand(CLI &cli, DefaultIO &dio) : Command(cli, "display results", dio) {}
// this function send the classification of data to the client.
void PrintCommand::execute()
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
    this->dio.write(this->cli.getTestClassifications() + "\nDone.\n");
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/PrintCommand.cpp
}