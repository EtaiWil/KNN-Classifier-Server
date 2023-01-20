using namespace std;
//this is an absract class for the IO operations.
class StandartIO : public DefaultIO{
virtual string read();
virtual void write(string s);
};