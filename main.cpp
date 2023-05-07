#include "CLI.h"
#include "StandartIO.h"
using namespace std;

int main(){
    StandartIO sio;

    CLI cli(sio);
        cli.start();
    cout<<"done"<<endl;
    return 0;
}
