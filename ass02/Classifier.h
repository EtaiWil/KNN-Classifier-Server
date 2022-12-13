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
    void getClassifiedVectors(istream& is);
    string Classify(const vector<double> &Vector);
    ~Classifier();

};
#endif