#ifndef KNNCALCCAN_H_
#define KNNCALCCAN_H_

#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcCan : public CalculatorKnn {
    private:
    //implemets the virtual method to calculate distance 
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    //constructor
    KnnCalcCan(int k,list<tuple<vector<double>,string>>& classifiedVectors);
    KnnCalcCan (const KnnCalcCan& other); //copy constructor
    KnnCalcCan& operator= (const KnnCalcCan& other); //copy assignment operator
    KnnCalcCan (KnnCalcCan&& other) noexcept=default; //move constructor
    KnnCalcCan& operator= (KnnCalcCan&& other) noexcept; //move assignment operator
    ~KnnCalcCan()=default; //destructor
};
#endif