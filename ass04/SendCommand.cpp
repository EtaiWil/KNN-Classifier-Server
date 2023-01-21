#include "SendCommand.h"
SendCommand::SendCommand(CLI& cli,DefaultIO &dio):Command(cli,"download results",dio){}
void SendCommand::execute() {
    if(!(this->cli.isClassifierTrained())||this->cli.isTestVectorsEmpty()){
        this->dio.write("please upload data");
        return;
    }
    if(!this->cli.isTestVectorsClassified()){
        this->dio.write("please classify the data");
        return;
    }
    this->dio.write(this->cli.getTestClassifications());
}