#include "ClassifyCommand.h"
ClassifyCommand::ClassifyCommand(CLI& cli,DefaultIO &dio):Command(cli,"classify data",dio){
}
void ClassifyCommand::execute(){
    if(this->cli.isTestVectorsEmpty()||!(this->cli.isClassifierTrained())){
        this->dio.write("please upload data");
        return;
    }
    try{
    this->cli.classifyTestVectors();
    }catch (std::invalid_argument e){
        this->dio.write("error classifying vectors");
        return;
}
    this->dio.write("classifying data complete");
 }
