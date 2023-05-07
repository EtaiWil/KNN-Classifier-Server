<<<<<<< HEAD:Command.cpp
#include "Command.h"


Command::Command(CLI &cli ,string description,DefaultIO& dio):cli(cli),description(description),dio(dio){
}
string Command::getDesc(){
    return this->description;
=======
#include "Command.h"

Command::Command(CLI &cli, string description, DefaultIO &dio) : cli(cli), description(description), dio(dio)
{
}
string Command::getDesc()
{
    return this->description;
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/Command.cpp
}