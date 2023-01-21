#include "SettingCommand.h"
SettingCommand::SettingCommand(CLI& cli,DefaultIO &dio):Command(cli,"algorithm settings",dio){
}
//check what yoav answser to dekel about printng erors for the k and the metric.
void SettingCommand::execute(){
    dio.write("The current KNN parameters are: K = "+to_string(this->cli.getK())+", distance metric = "+this->cli.getDistanceMetric());
    string input = dio.read();
    if(!input.empty()){
        std::istringstream iss(input);
        std::string token;
        vector<string> tokens;
        // split by any ','
        while (std::getline(iss, token, ' '))
        {
            tokens.push_back(token);
        }
        //if nothing sent
        if(tokens.empty()){
            this->dio.write("invalid value for K");
            this->dio.write("invalid value for metric");
            return;
        } else if(tokens.size()==1){
            if(isValidDistance(tokens[0])){
                this->dio.write("invalid value for K");
                return;
            }
            int number;
            try {
                 number= std::stoi(input);
                if(number<=0) {
                    this->dio.write("invalid value for K");
                    this->dio.write("invalid value for metric");
                    return;
                }
            } catch (std::invalid_argument) {
                this->dio.write("invalid value for K");
                this->dio.write("invalid value for metric");
                return;
            }
            } else if(tokens.size()==2){
        bool kFlag=true;
        bool metricFlag=true;
        int k = stoi(tokens[0]);
        if (k<=0){
            this->dio.write("invalid value for K");
            kFlag=false;
        }

        if(!isValidDistance(tokens[1])){
            this->dio.write("invalid value for metric");
            metricFlag=false;
        }
        if(kFlag && metricFlag) {
            this->cli.setK(k);
            this->cli.setDistanceMetric(tokens[1]);
        }
        return;

    } else{
            this->dio.write("too many inputs");
            return;
        }
    }
}

bool SettingCommand::isValidDistance(std::string distance) {
    return distance == "MIN" || distance == "MAN" || distance == "CHB" || distance == "AUC" || distance == "CAN";
}
