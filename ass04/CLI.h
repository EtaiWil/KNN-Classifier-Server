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
int k;
string distanceMetric;
list<tuple<vector<double>, string>> &testVectors;
vector<Command*>& commands;
DefaultIO &dio;
vector<Command*> &getCommands(DefaultIO& dio);
static bool isValidDouble(string s);
public:
CLI(DefaultIO &dio);
~CLI();
void reset();
void displayMenu();
int getMenuOption();
void getTrainVectors(string s);
void getTestVectors(string s);
void start();
int getK();
string getDistanceMetric();
void setK(int k);
void setDistanceMetric(string distanceMetric);
void classifyTestVectors();
bool isTestVectorsEmpty();
string getTestClassifications();
bool isTestVectorsClassified();
bool isClassifierTrained();



};
#endif