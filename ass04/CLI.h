#ifndef CLI_H_
#define CLI_H_
#include "Classifier.h"
#include "Command.h"
#include "DefaultIO.h"
#include <list>
#include <vector>
#include <tuple>
#include <sstream>
#include <string>

class Command;
class CLI {
private:
Classifier cl;
list<tuple<vector<double>, string>> &testVectors;
vector<Command*>& commands;
DefaultIO &dio;
vector<Command*> &getCommands();
 bool isValidDouble(string s);
public:
CLI(DefaultIO &dio);
void getTrainVectors(string s);
void getTestVectors(string s);
void start();


};
#endif