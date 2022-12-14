#ifndef KNNCALCAUC_H_
#define KNNCALCAUC_H_

#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcAuc : public CalculatorKnn {
    private:
    //implemets the virtual method to calculate distance 
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    //constructor
    KnnCalcAuc(int k,list<tuple<vector<double>,string>>& classifiedVectors);
    KnnCalcAuc (const KnnCalcAuc& other); //copy constructor
    KnnCalcAuc& operator= (const KnnCalcAuc& other); //copy assignment operator
    KnnCalcAuc (KnnCalcAuc&& other) noexcept=default; //move constructor
    KnnCalcAuc& operator= (KnnCalcAuc&& other) noexcept; //move assignment operator
    ~KnnCalcAuc()=default; //destructor
};
#endif