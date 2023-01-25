#include "KnnCalcMin.h"
// implements the virtual method to calc the minkowskiDistance between 2 vectors.
double KnnCalcMin::calculateDistance(const vector<double> &firstVector, const vector<double> &secondVector) const
{
	return Distance::minkowskiDistance(firstVector, secondVector, P);
}
KnnCalcMin::KnnCalcMin(list<tuple<vector<double>, string>> &classifiedVectors) : CalculatorKnn(classifiedVectors) {}

// copy assignment operator
KnnCalcMin &KnnCalcMin::operator=(const KnnCalcMin &other)
{
	if (this == &other)
	{
		return *this;
	}
	// Use the copy constructor and move assignment operator
	*this = KnnCalcMin(other);
	return *this;
}
// copy constructor
KnnCalcMin::KnnCalcMin(const KnnCalcMin &other) : CalculatorKnn(other.classifiedVectors)
{
}
// move assignment operator
KnnCalcMin &KnnCalcMin::operator=(KnnCalcMin &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	*this = KnnCalcMin(other);
	return *this;
}
