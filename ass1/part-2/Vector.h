#include <iostream>
class Vector{
private:
double* arrayVector;
int dimension;
public:
Vector(const double* array,int dimension);
int getDimension()const;
double getValue(int i) const;
bool isSameDimension(Vector v);
double euclideanDistance(Vector other);
double* convertFromStringToInt(std::string numbers);
//friend std::ostream& operator <<(std::ostream& os, const Vector& vec);

};