#include "Classifier.h"
#include <fstream>
#include <iostream>
#include <vector>
int main()
{
    Classifier cl = Classifier(3);
    ifstream infile;
    infile.open("datasets/iris/iris_classified.csv");
        cl.getClassifiedVectors(infile);
    infile.close();
    vector<double> v1={4.6,3.1,1.5,0.2};
    string s=cl.Classify(v1);
    return 0;
}