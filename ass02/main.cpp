#include "Classifier.h"
#include <fstream>
#include <iostream>
int main()
{
    Classifier cl = Classifier(3);
    ifstream infile;
    infile.open("datasets/iris/iris_classified.csv");
        cl.getClassifiedVectors(infile);
    infile.close();
    return 0;
}