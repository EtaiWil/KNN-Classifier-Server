#include "ClassifyCommand.h"
ClassifyCommand::ClassifyCommand(CLI& cli,DefaultIO &dio):Command(cli,"classify data",dio){
}
void ClassifyCommand::execute(){
    if(this->cli.isTestVectorsEmpty()||!(this->cli.isClassifierTrained())){
        this->dio.write("please upload data\n");
        return;
    }
    //check if there is an eror in the proccess of classifing the vectors.
    try{
    this->cli.classifyTestVectors();
    }catch (std::invalid_argument e){
        this->dio.write("error classifying vectors\n");
        return;
}
    this->dio.write("classifying data complete\n");
 }
