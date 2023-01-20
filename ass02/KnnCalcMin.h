#ifndef KNNCALCMIN_H_
#define KNNCALCMIN_H_
#define P 2
#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcMin : public CalculatorKnn {
    private:
    //implemets the virtual method to calculate distance 
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    KnnCalcMin(int k,list<tuple<vector<double>,string>>& classifiedVectors);
    KnnCalcMin (const KnnCalcMin& other); //copy constructor
    KnnCalcMin& operator= (const KnnCalcMin& other); //copy assignment operator
    KnnCalcMin (KnnCalcMin&& other) noexcept=default; //move constructor
    KnnCalcMin& operator= (KnnCalcMin&& other) noexcept; //move assignment operator
    ~KnnCalcMin()=default; //destructor
};
#endif