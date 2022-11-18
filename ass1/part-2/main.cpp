#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>
#include <exception>
#define P_MINKOWSKI 2
// check if the vectors have the same dimenstion
bool isSameDimension(const std::vector<double> &v1, const std::vector<double> &v2)
{
  return v1.size() == v2.size();
}
int isInt(double result)
{
  if (result == (int)result)
  {
    return 1;
  }
  return 0;
}
std::string addPointZero(double x){
  if(isInt(x)){
    return ".0";
  }
  return "";
}

// find minkowskiDistance (algorithm number 5 )
double minkowskiDistance(const std::vector<double> &v1, const std::vector<double> &v2, int p)
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

// manhattanDistance algorithm number 2
// i removed the p argument because we don't need him i think
double manhattanDistance(const std::vector<double> &v1, const std::vector<double> &v2)
{

  if (!isSameDimension(v1, v2))
  {
    throw std::invalid_argument("The Dimensions of the vectors are not the same");
  }
  return minkowskiDistance(v1, v2, 1);
}

// canberra_distance algotithm nubmer 4
// i removed the p argument because we don't need him i think.
double canberra_distance(const std::vector<double> &v1, const std::vector<double> &v2)
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
// chebyshevDistance algorithm number 3
double chebyshevDistance(const std::vector<double> &v1, const std::vector<double> &v2)
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
// find eculidean distance (algorithm number 1)
double euclideanDistance(const std::vector<double> &v1, const std::vector<double> &v2)
{
  return minkowskiDistance(v1, v2, 2);
}
int main()
{
  char delim[] = " ";
  // converting from string to double
  std::string input1;
  std::cout << "Please, enter first vector: ";
  std::getline(std::cin, input1);
  std::vector<double> vec1;
  std::string token;
  std::istringstream iss(input1);
  while (std::getline(iss, token, ' '))
  {
    vec1.push_back(std::stod(token));
  }

  std::string input2;
  std::cout << "Please, enter second vector: ";
  std::getline(std::cin, input2);
  std::vector<double> vec2;
  std::string token2;
  std::istringstream iss2(input2);
  while (std::getline(iss2, token2, ' '))
  {
    vec2.push_back(std::stod(token2));
  }
  double euclidian = euclideanDistance(vec1, vec2);
  double manhattan = manhattanDistance(vec1, vec2);
  double chebyshev = chebyshevDistance(vec1, vec2);
  double canberra = canberra_distance(vec1, vec2);
  double minkowski = minkowskiDistance(vec1, vec2, P_MINKOWSKI);
  std::cout << euclidian<<addPointZero(euclidian)<< std::endl;
  std::cout << manhattan<<addPointZero(manhattan)<< std::endl;
  std::cout << chebyshev<<addPointZero(chebyshev)<< std::endl;
  std::cout << canberra<<addPointZero(canberra)<< std::endl;
  std::cout << minkowski<<addPointZero(minkowski)<< std::endl;
  return 0;
}