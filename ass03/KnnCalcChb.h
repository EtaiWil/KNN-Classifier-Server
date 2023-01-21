#ifndef KNNCALCCHB_H_
#define KNNCALCCHB_H_

#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcChb : public CalculatorKnn {
    private:
      //implemets the virtual method to calculate distance 
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    //constructor
    KnnCalcChb(list<tuple<vector<double>,string>>& classifiedVectors);
    KnnCalcChb (const KnnCalcChb& other); //copy constructor
    KnnCalcChb& operator= (const KnnCalcChb& other); //copy assignment operator
    KnnCalcChb (KnnCalcChb&& other) noexcept=default; //move constructor
    KnnCalcChb& operator= (KnnCalcChb&& other) noexcept; //move assignment operator
    ~KnnCalcChb()=default; //destructor
};
#endif