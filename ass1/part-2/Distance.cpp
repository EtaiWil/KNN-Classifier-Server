#include "Distance.h"

// check if the vectors have the same dimenstion
 bool Distance::isSameDimension(const std::vector<double> &v1, const std::vector<double> &v2)
{
  return v1.size() == v2.size();
}
int Distance::isInt(double result)
{
  if (result == (int)result)
  {
    return 1;
  }
  return 0;
}
std::string Distance::addPointZero(double x){
  if(Distance::isInt(x)){
    return ".0";
  }
  return "";
}
// find eculidean distance (algorithm number 1)
double Distance::euclideanDistance(const std::vector<double> &v1, const std::vector<double> &v2)
{
  return minkowskiDistance(v1, v2, 2);
}
// manhattanDistance algorithm number 2

double Distance::manhattanDistance(const std::vector<double> &v1, const std::vector<double> &v2)
{

  if (!isSameDimension(v1, v2))
  {
    throw std::invalid_argument("The Dimensions of the vectors are not the same");
  }
  return minkowskiDistance(v1, v2, 1);
}

// chebyshevDistance algorithm number 3
double Distance::chebyshevDistance(const std::vector<double> &v1, const std::vector<double> &v2)
{
  if (!isSameDimension(v1, v2))
  {
    throw std::invalid_argument("The Dimensions of the vectors are not the same");
  }
  double max = 0;
  for (int i = 0; i < v1.size(); i++)
  {
    if (abs(v1[i] - v2[i]) > max)
    {
      max = abs(v1[i] - v2[i]);
    }
  }
  return max;
}

// canberra_distance algotithm nubmer 4
double Distance::canberra_distance(const std::vector<double> &v1, const std::vector<double> &v2)
{
  if (!isSameDimension(v1, v2))
  {
    throw std::invalid_argument("The Dimensions of the vectors are not the same");
  }
  double sum = 0;
  for(int i=0;i<v1.size();i++) {
    if(v1[i]==0.0 && v2[i]==0.0){
      continue;
    }
    double mona = abs(v2[i]-v1[i]);
    double denominator=abs(v2[i])+abs(v1[i]);
    sum += (mona/denominator);
  }
  return sum;
}


// find minkowskiDistance (algorithm number 5 )
double Distance::minkowskiDistance(const std::vector<double> &v1, const std::vector<double> &v2, int p)
{
  if (!isSameDimension(v1, v2))
  {
    throw std::invalid_argument("The Dimensions of the vectors are not the same");
  }
  double distance = 0;
  for (int i = 0; i < v1.size(); i++)
  {
    distance += pow(abs(v1[i] - v2[i]), p);
  }
  double power = (1 / (double)p);
  distance = pow(distance, power);
  return distance;
}