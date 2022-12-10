#include "KnnCalcAuc.h"
double KnnCalcAuc::calculateDistance(const vector<double> &firstVector,const vector<double> &secondVector) const{
    return Distance::euclideanDistance(firstVector,secondVector);
}
KnnCalcAuc::KnnCalcAuc(int k,list<tuple<vector<double>,string>>& classifiedVectors): CalculatorKnn(k,classifiedVectors) {}