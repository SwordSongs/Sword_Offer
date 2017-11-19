#include<iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n);
	int (*power(int f[][2],int n))[2]{
		//cout<<f[1][0]<<endl;
		if(n == 1)
			return f;
		else if(n%2 == 0) {
				int (*q)[2];
				int result[][2] = {{0,0},{0,0}};
				int a[][2] = {{0,0},{0,0}};
				int b[][2] = {{0,0},{0,0}};
				q = power(f,n/2);
				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j)
						a[i][j] = q[i][j];
				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j)
						b[i][j] = q[i][j];

				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j){
						for(int k=0;k<2;++k)
							result[i][j] += a[i][k] * b[k][j]; 
						}
					return result;
		}
		else {
			int (*q)[2];
			int result[][2] = {{0,0},{0,0}};
			int result1[][2] = {{0,0},{0,0}};
			int a[][2] = {{0,0},{0,0}};
				int b[][2] = {{0,0},{0,0}};
			q = power(f,(n-1)/2);
			for(int i=0;i<2;++i)
					for(int j=0;j<2;++j)
						a[i][j] = q[i][j];
				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j)
						b[i][j] = q[i][j];

				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j){
						for(int k=0;k<2;++k)
							result[i][j] += a[i][k] * b[k][j]; 
						}

					for(int i=0;i<2;++i)
						for(int j=0;j<2;++j){
							for(int k=0;k<2;++k)
								result1[i][j] += result[i][k] * f[k][j]; 
							}
					return result1;
		} 
	}
};

/*int Solution::Fibonacci(int n) {
	if(n == 0)
			return 0;
		else if(n == 1)
			return 1;
		else {
			int a = 0;
			int b = 1;
			int result = 0;
			for(int i = 1;i<n;++i){
				result = a + b;
				a = b;
				b = result;
			}
			return result;
		}
}*/

int Solution::Fibonacci(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else{
		int (*p)[2];
		int f[][2] = {{1,1},{1,0}};
		p = power(f,n-1);
		return p[0][0];
	}
}




int main( ) {
	Solution s;
	int arr[] = {6,7,8,9,10};
	int *ptr = arr;
	*(ptr++) += 123;
	//printf("%d,%d",*ptr,*(++ptr));
	cout<<*ptr<<","<<*(++ptr)<<endl;
	system("pause");
	return 0;
}