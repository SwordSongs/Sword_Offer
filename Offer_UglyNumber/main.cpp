#include<iostream>
#include<ctime>
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index);
	friend int Min(int number1,int number2,int number3);
};

int Min(int number1,int number2,int number3) {
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

int Solution::GetUglyNumber_Solution(int index) {
	int *uglyNumbers  =  new int[index];
	uglyNumbers[0] = 1;
	int* p2 = uglyNumbers;
	int* p3 = uglyNumbers;
	int* p5 = uglyNumbers;
	int nextIndex = 1;

	while(nextIndex < index) {
		uglyNumbers[nextIndex]  = Min( (*p2) * 2,(*p3)*3,(*p5)*5);

		while((*p2)*2 <= uglyNumbers[nextIndex])
			  ++p2;
		while((*p3)*3 <= uglyNumbers[nextIndex])
			++p3;
		while((*p5)*5 <= uglyNumbers[nextIndex])
			++p5;

		++nextIndex;
	}

	int result = uglyNumbers[index-1];

	delete[] uglyNumbers;
	uglyNumbers = NULL;

	return result;
}

int main( ) {
	Solution s;
	clock_t start,end;
	start = clock( );
	int  result = s.GetUglyNumber_Solution(1500);
	end = clock( );
	cout <<result<<endl;
	cout<<"time:  "<<end-start<<" ms"<<endl;
	system("pause");
	return 0;
}