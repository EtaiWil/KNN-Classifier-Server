#include "UploadCommand.h"

 UploadCommand::UploadCommand(CLI& cli,DefaultIO &dio):Command(cli,"upload an unclassified csv data file",dio){
}
 void UploadCommand::execute(){
    dio.write("Please upload your local train CSV file.");
    string input,data;
    bool doneRead=false;
    do{
        input=dio.read();
        if(!input.empty()) {
            if (input == "ERRORABORT") {
                return;
            }
            data.append(input);
        }
        std::size_t found = data.find("\n\n");
        if(found != std::string::npos) {
            data = data.substr(0, found);
            doneRead=true;
        }

    }while(!doneRead);
    cli.getTrainVectors(data);
    dio.write("Upload complete.\nPlease upload your local test CSV file.");
    data="";
    doneRead=false;
     do{
         input=dio.read();
         if(!input.empty()) {
             if (input == "ERRORABORT") {
                 return;
             }
             data.append(input);
         }
         std::size_t found = data.find("\n\n");
         if(found != std::string::npos) {
             data = data.substr(0, found);
             doneRead=true;
         }

     }while(!doneRead);

    cli.getTestVectors(data);
    dio.write("Upload complete.\n");

 }
