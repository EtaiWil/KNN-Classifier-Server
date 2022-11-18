#include "Distance.h"
#include <regex>
bool isValidDouble(std::string s){
  std::regex pattern ("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
  return std::regex_match(s,pattern);

}
std::vector<double> getUserInput(){
  std::string input;
  std::getline(std::cin, input);
  std::vector<double> vec;
  std::string token;
  std::istringstream iss(input);
  while (std::getline(iss, token, ' '))
  {
    if(!isValidDouble(token)){
      throw std::invalid_argument("Invalid arguments for the Vector");
    }
    vec.push_back(std::stod(token));
  }
  return vec;
}
int main()
{
  std::vector<double> vec1 = getUserInput();
  std::vector<double> vec2 = getUserInput();
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
