#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_
#include <vector>
#include <list>
#include <istream>
#include "CalculatorKnn.h"
#include <sstream>
#include <tuple>
#include <iostream>
#include <stdexcept>
#include <map>
#include "KnnCalcAuc.h"
#include "KnnCalcCan.h"
#include "KnnCalcMin.h"
#include "KnnCalcMan.h"
#include "KnnCalcChb.h"

using namespace std;
class Classifier
{
private:
    list<tuple<vector<double>, string>> &classifiedVectors;
    // using comopsition have a map of a caclcuatorknn as  a member.
    map<string, CalculatorKnn *> &calcs;
    bool isValidDouble(string s);
    // return Knn calcuator by given input .
    map<string, CalculatorKnn *> &getCalcs();

public:
    Classifier();
    Classifier(const Classifier &other);                // copy constructor
    Classifier &operator=(const Classifier &other);     // copy assignment operator
    Classifier(Classifier &&other) noexcept = default;  // move constructor
    Classifier &operator=(Classifier &&other) noexcept; // move assignment operator
    ~Classifier();                                      // destructor
    // used to delete what we allocate on the heap
    void reset() noexcept;
    // get the classified vectors into the vectors list from the given stream.
    void getClassifiedVectors(istream &is);
    // this function calcualte the distance based on input from the user create new knn based on the string
    string Classify(const vector<double> &Vector, int k, string distanceType);
    bool isTrained(); //returns true if it has vectors in his classifiedVectors list, and false otherwise.
};
#endif