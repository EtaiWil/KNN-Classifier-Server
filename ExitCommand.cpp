<<<<<<< HEAD:ExitCommand.cpp
#include "ExitCommand.h"
ExitCommand::ExitCommand(CLI& cli,DefaultIO &dio):Command(cli,"exit",dio){}
void ExitCommand::execute() {
//dont need to do nothing because
=======
#include "ExitCommand.h"
ExitCommand::ExitCommand(CLI &cli, DefaultIO &dio) : Command(cli, "exit", dio) {}
void ExitCommand::execute()
{
    // dont need to do nothing because evrything worked.
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/ExitCommand.cpp
}