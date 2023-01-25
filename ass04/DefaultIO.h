#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_
#include <string>
using namespace std;
//this is an absract class for the IO operations.
class DefaultIO{
public:
    DefaultIO()=default;
    //pure virtual method of read input.
virtual std::string read()=0;
//pure virtual metohd of wrtie method. 
virtual void write(std::string s)=0;
};
#endif