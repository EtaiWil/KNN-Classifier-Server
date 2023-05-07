<<<<<<< HEAD:SettingCommand.cpp
#include "SettingCommand.h"
SettingCommand::SettingCommand(CLI& cli,DefaultIO &dio):Command(cli,"algorithm settings",dio){
}
//check what yoav answser to dekel about printng erors for the k and the metric.
void SettingCommand::execute(){
    dio.write("The current KNN parameters are: K = "+to_string(this->cli.getK())+", distance metric = "+this->cli.getDistanceMetric()+"\n");
    string input = dio.read();
    if(input!="NOCHANGE"){
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
            this->dio.write("invalid value for K\n");
            this->dio.write("invalid value for metric\n");
            return;
        } else if(tokens.size()==1){
            if(isValidDistance(tokens[0])){
                this->dio.write("invalid value for K\n");
                return;
            }
            int number;
            try {
                 number= std::stoi(input);
                if(number<=0) {
                    this->dio.write("invalid value for K\n");
                    this->dio.write("invalid value for metric\n");
                    return;
                }
            } catch (std::invalid_argument) {
                this->dio.write("invalid value for K\n");
                this->dio.write("invalid value for metric\n");
                return;
            }
            } else if(tokens.size()==2){
        bool kFlag=true;
        bool metricFlag=true;
        int k = stoi(tokens[0]);
        if (k<=0){
            this->dio.write("invalid value for K\n");
            kFlag=false;
        }

        if(!isValidDistance(tokens[1])){
            this->dio.write("invalid value for metric\n");
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
=======
#include "SettingCommand.h"
SettingCommand::SettingCommand(CLI &cli, DefaultIO &dio) : Command(cli, "algorithm settings", dio)
{
}
// changing the K and the distance metric if needed, also checking if the input is valid.
void SettingCommand::execute()
{
    dio.write("The current KNN parameters are: K = " + to_string(this->cli.getK()) + ", distance metric = " + this->cli.getDistanceMetric() + "ENDOFSETTING");
    string input = dio.read();
    if (input != "NOCHANGE")
    {
        std::istringstream iss(input);
        std::string token;
        vector<string> tokens;
        // split by any ','
        while (std::getline(iss, token, ' '))
        {
            tokens.push_back(token);
        }
        // if nothing sent
        if (tokens.empty())
        {
            this->dio.write("invalid value for K\n");
            this->dio.write("invalid value for metric\n");
            return;
        }
        else if (tokens.size() == 1)
        {
            if (isValidDistance(tokens[0]))
            {
                this->dio.write("invalid value for K\n");
                return;
            }
            int number;
            try
            {
                number = std::stoi(input);
                if (number <= 0)
                {
                    this->dio.write("invalid value for K\n");
                    this->dio.write("invalid value for metric\n");
                    return;
                }
            }
            catch (std::invalid_argument)
            {
                this->dio.write("invalid value for K\n");
                this->dio.write("invalid value for metric\n");
                return;
            }
        }
        else if (tokens.size() == 2)
        {
            bool kFlag = true;
            bool metricFlag = true;
            int k = stoi(tokens[0]);
            if (k <= 0)
            {
                this->dio.write("invalid value for K\n");
                kFlag = false;
            }

            if (!isValidDistance(tokens[1]))
            {
                this->dio.write("invalid value for metric\n");
                metricFlag = false;
            }
            if (kFlag && metricFlag)
            {
                this->cli.setK(k);
                this->cli.setDistanceMetric(tokens[1]);
                dio.write("OKOK");
            }
            return;
        }
        else
        {
            this->dio.write("too many inputs");
            return;
        }
    }
    dio.write("OKOK");
}
// check if the distance is valid.
bool SettingCommand::isValidDistance(std::string distance)
{
    return distance == "MIN" || distance == "MAN" || distance == "CHB" || distance == "AUC" || distance == "CAN";
}
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/SettingCommand.cpp
