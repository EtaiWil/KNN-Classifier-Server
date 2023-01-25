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
// #predeclare the class so its in the scope
class Command;
// this class will be used as a CLI that is responsible to activate the right command and manage the data.
class CLI
{
private:
    Classifier cl;
    int k;
    string distanceMetric;
    list<tuple<vector<double>, string>> &testVectors;
    vector<Command *> &commands;
    DefaultIO &dio;
    // this method is used by the constructor to create the commands in the menu
    vector<Command *> &getCommands(DefaultIO &dio);
    // this method checks if a string is a valid double
    static bool isValidDouble(string s);

public:
    // constructor that gets an IO interface.
    CLI(DefaultIO &dio);
    // destructor
    ~CLI();
    // reset function to delete all the allocated data.
    void reset();
    // method to display the menu which has all the commands on the IO interface
    void displayMenu();
    // method to read a chosen option from the menu.
    int getMenuOption();
    // get the vectors into the classifier
    void getTrainVectors(string s);
    // get the test vectors from the user.
    void getTestVectors(string s);
    // start method to initiate the loop of handling a client.
    void start();
    // get the K from the user.
    int getK();
    // get the distance metric from the user.
    string getDistanceMetric();
    // set the given K in the member.
    void setK(int k);
    // set the given distance metric as a member.
    void setDistanceMetric(string distanceMetric);
    // use the classifier member to classify all the test vectors.
    void classifyTestVectors();
    // method that checks if there are no test vectors.
    bool isTestVectorsEmpty();
    // this method returns a string with all the classifications.
    string getTestClassifications();
    // this method goes over the test vectors and checks if one of them is not classified and returns false. returns true if all of the are classified.
    bool isTestVectorsClassified();
    // this method checks if the classifier has vectors in his train database.
    bool isClassifierTrained();
};
#endif