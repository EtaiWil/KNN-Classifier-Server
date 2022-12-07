#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <list>
#include <iostream>
//declaring all the functions we want to use to calculate distance
class caluclatorKNN {
private:
int k; //the k in the knn 
const std::vector<double> &v1;
virtual double calculateDistance( const std::vector<double> &otherVector)=0;//abstact method
static std::list <std::vector<double>> (std::istream );

public:
static std::string addPointZero(double x);
static double euclideanDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double manhattanDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double chebyshevDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double canberra_distance(const std::vector<double> &v1, const std::vector<double> &v2);
static double minkowskiDistance(const std::vector<double> &v1, const std::vector<double> &v2, int p);
};
