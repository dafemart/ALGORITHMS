#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
   string input;
   cout << "insert the numbers with a space delimiter and press enter" << endl;
   getline(cin,input);
   vector<int> elements;
   string current_element = "";
   std::string::size_type sz;   // alias of size_t
   int value = 0;
   for(auto& it : input){
      if(it == ' '){
         value = std::stoi (current_element,&sz);
         if(current_element != "") elements.push_back(value);
         current_element = "";
      }
      else current_element += it;
   }
   value = std::stoi(current_element,&sz);
   elements.push_back(value);
   
   size_t input_size = elements.size();
   int b[input_size];
   for(int i = 0; i < input_size; ++i)
      b[i] = 1;
   int max = 1;
   for(int i = 1; i < input_size; ++i){
       for(int j = 0; j < i; ++j){
           if(elements.at(i) > elements.at(j) &&
            b[i] < b[j] + 1)
             b[i] = b[j] + 1;
       }
       if(b[i] > max)
          max = b[i];
   }

   

   cout << "the length of the largest increasing sub-sequence is " 
        << max << endl;
}