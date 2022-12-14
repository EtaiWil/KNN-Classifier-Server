#include "KnnCalcChb.h"
//return the right distance by chebyshev. implemets the virtual method.
double KnnCalcChb::calculateDistance(const vector<double> &firstVector,const vector<double> &secondVector) const{
    return Distance::chebyshevDistance(firstVector,secondVector);
}
KnnCalcChb::KnnCalcChb(int k,list<tuple<vector<double>,string>>& classifiedVectors):CalculatorKnn(k,classifiedVectors){}

//copy assignment operator
KnnCalcChb& KnnCalcChb::operator= (const KnnCalcChb& other){
    if (this == &other) {
		return *this;
	}
	// Use the copy constructor and move assignment operator
	*this = KnnCalcChb(other);
	return *this;
}
//copy constructor 
 KnnCalcChb::KnnCalcChb(const KnnCalcChb& other): CalculatorKnn(other.k, other.classifiedVectors){
 }
 //move assignment operator
KnnCalcChb& KnnCalcChb::operator= (KnnCalcChb&& other) noexcept{
   if (this == &other) {
		return *this;
	}
    *this = KnnCalcChb(other);
	return *this;
  }
 
