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
    this->dio.write(this->cli.getTestClassifications());
    this->dio.write("Done.");

}