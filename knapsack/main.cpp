#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
using knapsack_pair = pair<int,int>; // pair<value,weight>
using matrix_value_type = pair<int, vector<knapsack_pair>>; // pair<max, vec of elements>

matrix_value_type max(matrix_value_type first_value, matrix_value_type second_value){
      if(first_value.first >= second_value.first)
         return  first_value;
      else return second_value;
}

int main(){
    int number_of_values;
    int knapsack_size;
    cout << "How many values are you going to enter?" << endl;
    cin >> number_of_values;
    cout << "what's the size of the knapsack?" << endl;
    cin >> knapsack_size;
    int counter = 0;
    vector<knapsack_pair> knapsack_vector;
    while(counter < number_of_values){
        knapsack_pair new_pair;
        cout << "insert the value of the element" << endl;
        cin >> new_pair.first;
        cout << "insert the weight of the element" << endl;
        cin >> new_pair.second;
        knapsack_vector.push_back(new_pair);
        ++counter;
    }
    matrix_value_type matrix[number_of_values + 1][knapsack_size + 1];
    for(int i = 0; i < knapsack_size + 1; ++i){
        vector<knapsack_pair> empty_vec;
        matrix_value_type value(0,empty_vec);
        matrix[0][i] = value;
    }

    for(int x = 1; x < number_of_values + 1; ++x){
        knapsack_pair current_pair = knapsack_vector.at(x-1);
        for(int y = 0; y < knapsack_size + 1; ++y){
            matrix_value_type first_value = matrix[x-1][y];
            matrix_value_type second_value;
            int weight_s_pair = y - current_pair.second;
            if(weight_s_pair >= 0){
               second_value = matrix[x-1][weight_s_pair];
               second_value.first = second_value.first + current_pair.first;
               second_value.second.push_back(current_pair);
            }
            else second_value.first = -999;
            matrix[x][y] = max(first_value,second_value);
        }
    }

    matrix_value_type result = matrix[number_of_values][knapsack_size];
    cout << "the max value is: " << result.first << endl;
    cout << "the elements in the knapsack are: " << endl;
    for(auto& it : result.second)
        cout << "element of value: " << it.first << " and weight: " << it.second <<endl;
}   