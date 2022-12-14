#include "KnnCalcAuc.h"
//implement the virtual method. return the right distance.
double KnnCalcAuc::calculateDistance(const vector<double> &firstVector,const vector<double> &secondVector) const{
    return Distance::euclideanDistance(firstVector,secondVector);
}
KnnCalcAuc::KnnCalcAuc(int k,list<tuple<vector<double>,string>>& classifiedVectors):CalculatorKnn(k,classifiedVectors){}

//copy assignment operator
KnnCalcAuc& KnnCalcAuc::operator= (const KnnCalcAuc& other){
    if (this == &other) {
		return *this;
	}
	// Use the copy constructor and move assignment operator
	*this = KnnCalcAuc(other);
	return *this;
}
//copy constructor 
 KnnCalcAuc::KnnCalcAuc(const KnnCalcAuc& other): CalculatorKnn(other.k, other.classifiedVectors){
 }
 //move assignment operator
KnnCalcAuc& KnnCalcAuc::operator= (KnnCalcAuc&& other) noexcept{
   if (this == &other) {
		return *this;
	}
    *this = KnnCalcAuc(other);
	return *this;
  }
 
