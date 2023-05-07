
#include "StandartIO.h"
string StandartIO::read(){
    string s;
    getline(cin,s);
    return s;
}
void StandartIO::write(string s){
cout<<s<<endl;
}
