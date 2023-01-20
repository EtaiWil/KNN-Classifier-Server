#include "UploadCommand.h"

 UploadCommand::UploadCommand(CLI& cli,string description,DefaultIO& dio):Command(cli,description,dio){}
 void UploadCommand::execute(){
    dio.write("Please upload your local train CSV file.");
    string input=dio.read();
    cli.getTrainVectors(input);
    dio.write("Upload complete.");
    dio.write("Please upload your local test CSV file.");
    input=dio.read();
    cli.getTestVectors(input);
    dio.write("Upload complete.");

 }
