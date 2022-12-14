#ifndef CALCULATORKNN_H_
#define CALCULATORKNN_H_
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <list>
#include <tuple>
#include <iostream>
#include <map>

using namespace std;
//declaring all the functions we want to use to calculate distance
class CalculatorKnn{
private:
int k; //the k in the knn
list<tuple<vector<double>,string>>& classifiedVectors;
virtual double calculateDistance(const vector <double> &firstVector,const vector <double> &secondVector) const=0; //abstact method
static bool comperator(tuple<string,double> v1,tuple<string,double> v2);

public:
    CalculatorKnn(int k,list<tuple<vector<double>,string>>& classifiedVectors);
    string Classify(const vector<double> &Vector) const;
};
#endif