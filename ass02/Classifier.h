#include <vector>
#include <list>
#include <istream>
//#include "CalculatorKnn.h"
#include <sstream>
#include <tuple>
#include <iostream>

using namespace std;
class  Classifier
{
private:
    list<tuple<vector<double>,string>> classifiedVectors;
    //CaluclatorKnn& caluclator;
    int k;

    bool isValidDouble(string s);

public:
    Classifier(int k);
    void getClassifiedVectors(istream& is);
    ~Classifier();

};