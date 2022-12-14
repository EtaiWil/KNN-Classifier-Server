#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_
#include <vector>
#include <list>
#include <istream>
#include "CalculatorKnn.h"
#include <sstream>
#include <tuple>
#include <iostream>
#include "KnnCalcAuc.h"

using namespace std;
class  Classifier
{
private:
    int k;
    list<tuple<vector<double>,string>>& classifiedVectors;
    const CalculatorKnn& calc;
    bool isValidDouble(string s);

public:
    Classifier(int k);
    //Classifier (const Classifier& other); //copy constructor
    //Classifier &operator= (const Classifier& other); //copy assignment operator
    //Classifier (Classifier&& other) noexcept;
    void getClassifiedVectors(istream& is);
    string Classify(const vector<double> &Vector);
    ~Classifier();

};
#endif