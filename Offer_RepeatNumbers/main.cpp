#include<iostream>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* &duplication);
};

 bool Solution::duplicate(int numbers[], int length, int* &duplication){
     if(length <= 0)
         return false;

     duplication = numbers;          //指向第一个元素
     int temp;
     unsigned index = 0;
	
     while(duplication != &numbers[length-1]){
         if(*duplication == index){
             ++duplication;
             ++index;
         }
		 else if(*duplication != index){
			          if(*duplication == numbers[*duplication]){
							 return true;
						  }
					  else{
								temp = numbers[*duplication];
								numbers[*duplication] = *duplication;
							   *duplication = temp;
					  }
         }
         
     }
     return false;
 }

int main( ) {
	Solution s;
	int numbers[] = {2,1,3,2,4};
	int* d = NULL;
	bool b = s.duplicate(numbers,7,d);
	cout<<"bool ="<<b<<" , duplication = "<<*d<<endl;

	system("pause");
	return 0;
}