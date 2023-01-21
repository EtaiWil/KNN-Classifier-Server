#include "UploadCommand.h"

 UploadCommand::UploadCommand(CLI& cli,DefaultIO &dio):Command(cli,"upload an unclassified csv data file",dio){
}
 void UploadCommand::execute(){
    dio.write("Please upload your local train CSV file.");
    string input,data;
    do{
        input=dio.read();
        if(!input.empty())
            data.append(input);
    }while(input.substr(input.length() -2)!="\n\n");
    cli.getTrainVectors(data);
    dio.write("Upload complete.");
    dio.write("Please upload your local test CSV file.");
    data="";
     do{
         input=dio.read();
         if(!input.empty())
             data.append(input);
     }while(input.substr(input.length() -2)!="\n\n");

    cli.getTestVectors(data);
    dio.write("Upload complete.");

 }
