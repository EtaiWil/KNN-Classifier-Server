#ifndef STANDARTIO_H_
#define STANDARTIO_H_
#include "DefaultIO.h"
#include <string>
#include <iostream>
using namespace std;


//this is an class for the IO operations from terminal.
class StandartIO : public DefaultIO {
public:
    StandartIO()=default;
    virtual std::string read();
    virtual void write(std::string s);
};
#endif
