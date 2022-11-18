#include <exception>
#include <iostream>
#include "Vector.h"

Vector::Vector(const double* array,int dimension){
this->arrayVector=new double[dimension];
this->dimension=dimension;
for(int i=0;i<dimension;i++){
    this->arrayVector[i]=array[i];
}
}
int Vector::getDimension()const{
    return this->dimension;
}
double Vector::getValue(int i) const{
    /*if(i>=dim){
        throw std::invalid_argument("Illegal Index");
    }*/
    return arrayVector[i];
}
bool Vector::isSameDimension(Vector v){
    return (this->dimension == v.dimension);
}

double Vector::euclideanDistance(Vector other){
    return 1.2;
}
double* Vector::convertFromStringToInt(std::string numbers){
    return nullptr;
}
//this function helps to print a vector it uses the operator overloading and builds a string for the vector
//then it uses the << operator on the ostream to print it
std::ostream& operator <<(std::ostream &os, const Vector &vec){
os<<"(";
for(int i=0;i<vec.getDimension()-1;i++){
os<<std::to_string(vec.getValue(i))<<",";
}
os<<std::to_string(vec.getValue(vec.getDimension()-1))<<")";
return os;
}

