#include "Distance.h"
#define P_MINKOWSKI 2
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
  double euclidian =  Distance::euclideanDistance(vec1, vec2);
  double manhattan = Distance::manhattanDistance(vec1, vec2);
  double chebyshev =Distance:: chebyshevDistance(vec1, vec2);
  double canberra = Distance::canberra_distance(vec1, vec2);
  double minkowski = Distance::minkowskiDistance(vec1, vec2, P_MINKOWSKI);
  std::cout << euclidian<<Distance::addPointZero(euclidian)<< std::endl;
  std::cout << manhattan<<Distance::addPointZero(manhattan)<< std::endl;
  std::cout << chebyshev<<Distance::addPointZero(chebyshev)<< std::endl;
  std::cout << canberra<<Distance::addPointZero(canberra)<< std::endl;
  std::cout << minkowski<<Distance::addPointZero(minkowski)<< std::endl;
  return 0;
}