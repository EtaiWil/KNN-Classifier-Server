#include "CalculatorKnn.h"

CalculatorKnn::CalculatorKnn(int k,list<tuple<vector<double>,string>>& classifiedVectors):k(k),classifiedVectors(classifiedVectors){ }
string CalculatorKnn::Classify(const vector<double> &Vector) const{
    vector<tuple<string,double>> distances;
    for(auto& cVector:this->classifiedVectors) {
       distances.push_back(make_tuple(get<1>(cVector),calculateDistance(Vector,get<0>(cVector))));
    }
   sort(distances.begin(),distances.end(),comperator);// sort in incresing order.
   map<std::string, int> types_counters;
   int max=0;
   string type="";
   //counting what are the k closest elements.
   for(int i=0;i<this->k;i++){
      types_counters[get<0>(distances[i])]+=1;
      if(types_counters[get<0>(distances[i])]>max){
         max = types_counters[get<0>(distances[i])];
         type=get<0>(distances[i]);
      }
   }
   return type;
}
bool CalculatorKnn::comperator(tuple<string,double> v1,tuple<string,double> v2){
    //if its return true its mean that v1 value is bigger then v2 value. sorting from the smallest element to the biggest element.
  return ((get<1>(v1)) < (get<1>(v2)));

}
CalculatorKnn::CalculatorKnn(const CalculatorKnn& other):k(k),classifiedVectors(other.classifiedVectors){}
CalculatorKnn& CalculatorKnn::operator=(const CalculatorKnn& other){
	return *this;
}
CalculatorKnn& CalculatorKnn::operator=(CalculatorKnn&& other) noexcept{
   return *this;
}