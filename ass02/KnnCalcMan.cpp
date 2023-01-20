#include "KnnCalcMan.h"
//implements the virtual method to calc the manhattanDistance between 2 vectors. 
double KnnCalcMan::calculateDistance(const vector<double> &firstVector,const vector<double> &secondVector) const{
    return Distance::manhattanDistance(firstVector,secondVector);
}
KnnCalcMan::KnnCalcMan(int k,list<tuple<vector<double>,string>>& classifiedVectors):CalculatorKnn(k,classifiedVectors){}

//copy assignment operator
KnnCalcMan& KnnCalcMan::operator= (const KnnCalcMan& other){
if (this == &other) {
	return *this;
	}
// Use the copy constructor and move assignment operator
*this = KnnCalcMan(other);
return *this;
}
//copy constructor 
 KnnCalcMan::KnnCalcMan(const KnnCalcMan& other): CalculatorKnn(other.k, other.classifiedVectors){
 }
 //move assignment operator
KnnCalcMan& KnnCalcMan::operator= (KnnCalcMan&& other) noexcept{
   if (this == &other) {
		return *this;
	}
    *this = KnnCalcMan(other);
	return *this;
  }
 
