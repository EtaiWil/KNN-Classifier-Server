<<<<<<< HEAD:DefaultIO.h
#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_
#include <string>
using namespace std;
//this is an absract class for the IO operations.
class DefaultIO{
public:
    DefaultIO()=default;
virtual std::string read()=0;
virtual void write(std::string s)=0;
};
=======
#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_
#include <string>
using namespace std;
// this is an absract class for the IO operations.
class DefaultIO
{
public:
    DefaultIO() = default;
    // pure virtual method of read input.
    virtual std::string read() = 0;
    // pure virtual metohd of wrtie method.
    virtual void write(std::string s) = 0;
};
>>>>>>> 3763a6365ec2e7018a0f082843e782021879fb4b:ass04/DefaultIO.h
#endif