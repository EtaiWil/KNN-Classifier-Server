#include "KnnCalcCan.h"
// return the right distnace by canberra.
double KnnCalcCan::calculateDistance(const vector<double> &firstVector, const vector<double> &secondVector) const
{
	return Distance::canberra_distance(firstVector, secondVector);
}
KnnCalcCan::KnnCalcCan(list<tuple<vector<double>, string>> &classifiedVectors) : CalculatorKnn(classifiedVectors) {}

// copy assignment operator
KnnCalcCan &KnnCalcCan::operator=(const KnnCalcCan &other)
{
	if (this == &other)
	{
		return *this;
	}
	// Use the copy constructor and move assignment operator
	*this = KnnCalcCan(other);
	return *this;
}
// copy constructor
KnnCalcCan::KnnCalcCan(const KnnCalcCan &other) : CalculatorKnn(other.classifiedVectors)
{
}
// move assignment operator
KnnCalcCan &KnnCalcCan::operator=(KnnCalcCan &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	*this = KnnCalcCan(other);
	return *this;
}
