#include "DefaultIO.h";

using namespace std;
Class Command{
protected:
string description;
DefaultIO &dio;
public:
    Command(string desription,&DefaultIO &dio);
    virtual void execute()=0;

};