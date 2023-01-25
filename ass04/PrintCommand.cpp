#include "PrintCommand.h"
PrintCommand::PrintCommand(CLI& cli,DefaultIO &dio):Command(cli,"display results",dio){}
//this function send the classification of data to the client.
void PrintCommand::execute() {
    if(!(this->cli.isClassifierTrained())||this->cli.isTestVectorsEmpty()){
        this->dio.write("please upload data\n");
        return;
    }
    if(!this->cli.isTestVectorsClassified()){
        this->dio.write("please classify the data\n");
        return;
    }
    this->dio.write(this->cli.getTestClassifications()+"\nDone.\n");

}