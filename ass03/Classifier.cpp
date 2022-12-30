#include "Classifier.h"
//constactor. create new list and a new object to caluclate the knn algorithm. using abstraction.
Classifier::Classifier(int k,string distance):k(k),classifiedVectors(*(new list<tuple<vector<double>,string>>)),calc(getCalc(distance)){}
//insert every element to the list from the file 
void  Classifier::getClassifiedVectors(istream& is)
{
    string s;
    while(getline(is,s)) {
        //getting all the line fromn the user.
        std::vector<double> vec;
        //split the input into tokens every time in the line that "" is appering the token store the string before the "".
        std::string token;
        //read the data into the stringstream
        std::istringstream iss(s);
        tuple<vector<double>, string> classifiedItem;
        vector<string> tokens;
        //split by any ',' (',' key)
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size() - 1; i++) {
            if (!isValidDouble(tokens[i])) {
                throw invalid_argument("Invalid arguments for the Vector");
            }
            //insert the input into the vector.
            get<0>(classifiedItem).push_back(stod(tokens[i]));
        }
        get<1>(classifiedItem) = tokens[tokens.size() - 1];
        this->classifiedVectors.push_back(classifiedItem);
     
    }
}
//distractor
Classifier::~Classifier(){
reset();
}

//copy constructor 
  Classifier::Classifier (const Classifier& other):k(k),classifiedVectors(other.classifiedVectors),calc(other.calc){
   }
//copy assignment operator
Classifier& Classifier::operator= (const Classifier& other){
    if (this == &other) {
		return *this;
	}
	reset();
	// Use the copy constructor and move assignment operator
	*this = Classifier(other);
	return *this;
}
//move assignment operator
Classifier&  Classifier::operator= (Classifier&& other) noexcept{
	if (this == &other) {
		return *this;
	}

	reset();
    *this=Classifier(other);
	return *this;
}


//get the type of the vector we want to clasify
string Classifier::Classify(const vector<double> &Vector){
    return this->calc.Classify(Vector);
}
// this function check if the input from the user is valid.
bool Classifier::isValidDouble(string s){
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
//clean everything we do in the heap.
void Classifier::reset() noexcept
{
    delete(&calc);
	delete(&classifiedVectors);
}
//this function calcualte the distance based on input from the user
CalculatorKnn& Classifier::getCalc(string distanceType){
if(distanceType=="AUC"){
    return *(new KnnCalcAuc(this->k,this->classifiedVectors));
}
else if(distanceType=="MAN"){
return *(new KnnCalcAuc(this->k,this->classifiedVectors));
}
else if(distanceType=="CHB"){
return *(new KnnCalcChb(this->k,this->classifiedVectors));
}
else if(distanceType=="CAN"){
return *(new KnnCalcCan(this->k,this->classifiedVectors));
}
else if(distanceType=="MIN"){
return *(new KnnCalcMin(this->k,this->classifiedVectors));
}
else{
    std::cout<<"not a valid distance name - Auclidian Calculator instead"<<std::endl;
    return *(new KnnCalcAuc(this->k,this->classifiedVectors));
}
}