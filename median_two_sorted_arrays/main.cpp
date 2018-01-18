#include <iostream>
#include <math.h>
using namespace std;

float median_h(int arr[], int size){
  float median = 0.0;
  if(size%2 == 0)
    median = (arr[size/2] + arr[(size/2)-1])/2;
  else median = arr[(int)ceil((float)size/(float)2)];
  return median;
}

float median(int arr1[], int arr2[], int size_1, int size_2){
   if(size_1 == 1)
      return (arr1[0] + arr2[0])/2;

   float m1 = median_h(arr1,size_1);
   float m2 = median_h(arr2,size_2);
   float median_res = 0.0;

   if(m1 == m2)
      median_res = m1;
   else{
     int index = 0;
     int size = ceil((float)size_1/(float)2);
     (size_1 % 2 == 0)? index = size_1/2 : index = floor(size_1/2); 
     if(m1 < m2)
       median_res = median(arr1 + index,arr2, size, size);    
     else
       median_res = median(arr1,arr2 + index, size, size);
   }
   return median_res;
}



int main(void){
    int arr1[] = {1,2,3,6};
    int arr2[] = {4,6,8,10};

    float med = median(arr1,arr2,5,5);
    cout << med << endl;
  
}