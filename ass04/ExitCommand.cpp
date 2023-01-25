#include "ExitCommand.h"
ExitCommand::ExitCommand(CLI& cli,DefaultIO &dio):Command(cli,"exit",dio){}
void ExitCommand::execute() {
//dont need to do nothing because evrything worked.
}