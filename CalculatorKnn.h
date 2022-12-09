#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <list>


using namespace std;
//declaring all the functions we want to use to calculate distance
class CalculatorKnn{
private:
int k; //the k in the knn 
list<tuple<vector<double>,string>> classifiedVectors;
virtual double calculateDistance(const vector<double> &firstVector,const vector<double> &secondVector)=0; //abstact method

public:
    CalculatorKnn(int k,list<tuple<vector<double>,string>> classifiedVectors);
    string Classify(const vector<double> &Vector);
};
