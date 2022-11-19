#include "Distance.h"
bool isValidDouble(std::string s){
  if(s.length() == 0) {
    return false;
  }
   std::size_t found = s.find_first_not_of("0123456789.-");
  if (found!=std::string::npos)
  {
    return false;
  }
  if(s[0] == '.'){
    return false;
  }
  return true;

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
  std::vector<double> vec1;
  std::vector<double> vec2;
  try{
  vec1 = getUserInput();
  vec2 = getUserInput();
  }catch(std::exception e){
    std::cout<<"Invalid arguments for the Vector"<<std::endl;
    return 1;
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
