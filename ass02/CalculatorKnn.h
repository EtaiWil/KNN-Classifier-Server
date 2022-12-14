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
//abstract method that calcuate distnace between 2 vectors.
virtual double calculateDistance(const vector <double> &firstVector,const vector <double> &secondVector) const=0; 
//comperator to compare between vectors.
static bool comperator(tuple<string,double> v1,tuple<string,double> v2);
protected:
//the k in the knn
int k; 
//list that the elemets are tules, every tuple contain vector from type double. and the other size of the tuple is string.
list<tuple<vector<double>,string>>& classifiedVectors;
public:
//constractor
    CalculatorKnn(int k,list<tuple<vector<double>,string>>& classifiedVectors);
     //calculating what object repeat the most in the k closet elements.
    string Classify(const vector<double> &Vector) const;\
    //the other are the implemets of rule of 5.
    CalculatorKnn(const CalculatorKnn& other);
	CalculatorKnn& operator=(const CalculatorKnn& other);
	CalculatorKnn(CalculatorKnn&& other) noexcept=default;
	CalculatorKnn& operator=(CalculatorKnn&& other) noexcept;
    ~CalculatorKnn()=default;
};
#endif