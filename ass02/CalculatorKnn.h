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
#include <algorithm>

using namespace std;
//declaring all the functions we want to use to calculate distance
class CalculatorKnn{
private:
virtual double calculateDistance(const vector <double> &firstVector,const vector <double> &secondVector) const=0; //abstact method
static bool comperator(tuple<string,double> v1,tuple<string,double> v2);
protected:
int k; //the k in the knn
list<tuple<vector<double>,string>>& classifiedVectors;
public:
    CalculatorKnn(int k,list<tuple<vector<double>,string>>& classifiedVectors);
    string Classify(const vector<double> &Vector) const;
    CalculatorKnn(const CalculatorKnn& other);
	CalculatorKnn& operator=(const CalculatorKnn& other);
	CalculatorKnn(CalculatorKnn&& other) noexcept=default;
	CalculatorKnn& operator=(CalculatorKnn&& other) noexcept;
    ~CalculatorKnn()=default;
};
#endif