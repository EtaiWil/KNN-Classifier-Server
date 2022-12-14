#include "Classifier.h"
Classifier::Classifier(int k):k(k),classifiedVectors(*(new list<tuple<vector<double>,string>>)),calc(*(new KnnCalcAuc(k,classifiedVectors))){}//,classifiedVectors(list<tuple<vector<double>,string>>()) {
   // this->calc=KnnCalcAuc(k,classifiedVectors);
   /* this->k=k;
    this->classifiedVectors = list<tuple<vector<double>,string>>();// create a list of vectors
    this->calc=KnnCalcAuc(k,classifiedVectors);
//this->caluclator=(CaluclatorKnn&)nullptr;
*/
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
        cout<<"("<<get<0>(classifiedItem)[0]<<","<<get<1>(classifiedItem)<<")"<<endl;
    }
}
Classifier::~Classifier(){
// add a destructor.
}
/*
//copy constructor 
  Classifier::Classifier (const Classifier& other):k(k),classifiedVectors(other.classifiedVectors),calc(other->calc){
   }
//copy assignment operator
Classifier &operator= (const Classifier& other){
    delete(this);
    return Classifier::classifier(other);
}
//move assignment constructor
Classifier::Classifier (Classifier&& other){

}
*/

string Classifier::Classify(const vector<double> &Vector){
    return this->calc.Classify(Vector);
}
// this function check if the input from the user is valid.
bool Classifier::isValidDouble(string s){
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