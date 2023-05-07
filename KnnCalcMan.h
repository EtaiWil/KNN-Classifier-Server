#ifndef KNNCALCMAN_H_
#define KNNCALCMAN_H_

#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcMan : public CalculatorKnn {
    private:
     //implemets the virtual method to calculate distance 
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    //constructor 
    KnnCalcMan(list<tuple<vector<double>,string>>& classifiedVectors);
    KnnCalcMan (const KnnCalcMan& other); //copy constructor
    KnnCalcMan& operator= (const KnnCalcMan& other); //copy assignment operator
    KnnCalcMan (KnnCalcMan&& other) noexcept=default; //move constructor
    KnnCalcMan& operator= (KnnCalcMan&& other) noexcept; //move assignment operator
    ~KnnCalcMan()=default; //destructor
};
#endif