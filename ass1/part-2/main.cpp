
#include "Distance.h"
// this function check if the input from the user is valid. 
bool isValidDouble(std::string s){
  if(s.length() == 0) {
    return false;
  }
  // we want to get from the user only this characters "0123456789.-" as they represent Double number.
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
//this function get the input from the user and then insert the valid input into vector.
std::vector<double> getUserInput(){
  std::string input;
  //getting all the line fromn the user.
  std::getline(std::cin, input);
  std::vector<double> vec;
  //split the input into tokens every time in the line that "" is appering the token store the string before the "".
  std::string token;
  //read the data into the stringstream
  std::istringstream iss(input);
  //split by any '' (space key)
  while (std::getline(iss, token, ' '))
  {
    // check if the input is valid
    if(!isValidDouble(token)){
      throw std::invalid_argument("Invalid arguments for the Vector");
    }
    //insert the input into the vector.
    vec.push_back(std::stod(token));
  }
  return vec;
}
int main()
{
  //declare two vectors to store the data from the user.
  std::vector<double> vec1;
  std::vector<double> vec2;
  try{
  vec1 = getUserInput();
  vec2 = getUserInput();
  }catch(std::exception e){
    std::cout<<"Invalid arguments for the Vector"<<std::endl;
    return 1;
  }
  //decleration of the variables
   double euclidian;
   double manhattan;
    double chebyshev;
     double canberra;
     double minkowski;
    //check if the 2 vecotrs have the same dimension.
  try
  {
    euclidian =  Distance::euclideanDistance(vec1, vec2);
   manhattan = Distance::manhattanDistance(vec1, vec2);
   chebyshev =Distance:: chebyshevDistance(vec1, vec2);
  canberra = Distance::canberra_distance(vec1, vec2);
   minkowski = Distance::minkowskiDistance(vec1, vec2, P_MINKOWSKI);
  }
  catch(const std::exception& e)
  {
    std::cout<<"The Dimensions of the vectors are not the same"<<std::endl;
  }
  //return the answers.
  std::cout << euclidian<<Distance::addPointZero(euclidian)<< std::endl;
  std::cout << manhattan<<Distance::addPointZero(manhattan)<< std::endl;
  std::cout << chebyshev<<Distance::addPointZero(chebyshev)<< std::endl;
  std::cout << canberra<<Distance::addPointZero(canberra)<< std::endl;
  std::cout << minkowski<<Distance::addPointZero(minkowski)<< std::endl;
  return 0;

}
