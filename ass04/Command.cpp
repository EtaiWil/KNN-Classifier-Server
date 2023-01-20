#include "Command.h"

Command::Command(CLI &cli ,string desription,DefaultIO &dio):cli(cli),description(description),dio(dio){
}
string Command::getDesc(){
    return this->description;
}