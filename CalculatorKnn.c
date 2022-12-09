#include "CalculatorKnn.h"

CalculatorKnn::CalculatorKnn(int k, list<tuple<vector<double>,string>> classifiedVectors){
    this->k=k;
    this->classifiedVectors=classifiedVectors;
}