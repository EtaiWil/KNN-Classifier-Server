#include "CalculatorKnn.h"

CalculatorKnn::CalculatorKnn(int k, list<tuple<vector<double>,string>>& classifiedVectors):k(k),classifiedVectors(classifiedVectors){ }
string CalculatorKnn::Classify(const vector<double> &Vector) const{
    list<tuple<string,double>> distances;
    for(auto& cVector:this->classifiedVectors) {
       distances.push_back(make_tuple(get<1>(cVector),calculateDistance(Vector,get<0>(cVector))));
    }
    distances.sort(comperator);// sort in incresing order.
    for(auto& dVector:distances) {
       cout<<get<0>(dVector)<<"  "<<get<1>(dVector)<<endl;
    }
    return "a";
}
bool CalculatorKnn::comperator(tuple<string,double> v1,tuple<string,double> v2){
    //if its return true its mean that v1 value is bigger then v2 value. sorting from the smallest element to the biggest element.
  return ((get<1>(v1)) < (get<1>(v2)));




}