#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#define P_MINKOWSKI 2
class Distance {
private:
static bool isSameDimension(const std::vector<double> &v1, const std::vector<double> &v2);
static int isInt(double result);
public:
static std::string addPointZero(double x);
static double euclideanDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double manhattanDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double chebyshevDistance(const std::vector<double> &v1, const std::vector<double> &v2);
static double canberra_distance(const std::vector<double> &v1, const std::vector<double> &v2);
static double minkowskiDistance(const std::vector<double> &v1, const std::vector<double> &v2, int p);
};
#endif