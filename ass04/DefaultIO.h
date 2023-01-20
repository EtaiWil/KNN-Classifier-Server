using namespace std;
//this is an absract class for the IO operations.
class DefaultIO{
virtual string read()=0;
virtual void write(string s)=0;
};