#ifndef STANDARTIO_H_
#define STANDARTIO_H_
#include "DefaultIO.h"
#include <string>
#include <iostream>
using namespace std;


//this is an absract class for the IO operations.
class StandartIO : public DefaultIO {
virtual std::string read();
virtual void write(std::string s);
};
#endif
