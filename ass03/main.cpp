#include "Classifier.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>

// this function check if the input from the user is valid. 
bool isValidDouble(std::string s){
  if(s.length() == 0) {
    return false;
  }
  // we want to get from the user only this characters "0123456789.-" as they represent Double number.
   std::size_t found = s.find_first_not_of("0123456789.-Ee");
  if (found!=std::string::npos)
  {
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

int main(int argc,char *argv[])
{
if(argc!=4){
cout<<"no valid arguments for the program"<<std::endl;
return -1;
}
int k;
try{
  //check if its number
 k = atoi(argv[1]);
}
catch(exception e){
    cout<<"bad K argument"<<endl;
    return -1;
}
    string file_path=argv[2];
    string distance_type=argv[3];
    Classifier cl = Classifier();
    ifstream infile;
    try{
    infile.open(file_path);
    }
    catch(exception e){
        cout<<"problem opening file"<<endl;
    }
    //get the data from the file 
    cl.getClassifiedVectors(infile);
    infile.close();
    while(true){
    std::vector<double> vec1;
    try{
    vec1=getUserInput();
    } catch(exception e){
      std::cout<<"Invalid arguments for the Vector"<<std::endl;
    }
    try{
    //get the answer in s
    string s=cl.Classify(vec1,k,distance_type);
    std::cout<<s<<std::endl;
    }catch(exception e) {
      std::cout<<"Invalid Vector To Classify"<<std::endl;
    }
    }
    return 0;
}
