#ifndef KNNCALCAUC_H_
#define KNNCALCAUC_H_

#include "Distance.h"
#include "CalculatorKnn.h"
#include <list>
#include <tuple>
#include <vector>

class KnnCalcAuc : public CalculatorKnn {
    private:
    virtual double calculateDistance(const vector<double>& firstVector,const vector<double>& secondVector) const;
    public:
    KnnCalcAuc(int k,list<tuple<vector<double>,string>>& classifiedVectors);
};
#endif