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
#include "KnnCalcAuc.h"
#include "KnnCalcCan.h"
#include "KnnCalcMin.h"
#include "KnnCalcMan.h"
#include "KnnCalcChb.h"


using namespace std;
class  Classifier
{
private:
    int k;
    list<tuple<vector<double>,string>>& classifiedVectors;
    //using comopsition
    const CalculatorKnn& calc;
    bool isValidDouble(string s);
    //used to delete what we allocate on the heap
    void reset() noexcept;
    //return Knn calcuator by given input .
    CalculatorKnn& getCalc(string distanceType);
public:
    Classifier(int k, string distance);
    Classifier (const Classifier& other); //copy constructor
    Classifier& operator= (const Classifier& other); //copy assignment operator
    Classifier (Classifier&& other) noexcept=default; //move constructor
    Classifier& operator= (Classifier&& other) noexcept; //move assignment operator
    ~Classifier(); //destructor
    void getClassifiedVectors(istream& is);
    string Classify(const vector<double> &Vector);
   

};
#endif