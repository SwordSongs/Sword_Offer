#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Solution {
	public:
		vector<int> printMatrix(vector<vector<int> > &matrix);
};

vector<int> Solution::printMatrix(vector<vector<int> > &matrix) {
		vector<int> result;

		int top = 0;
		int buttom = matrix.size( );
		int left = 0;
		int right = matrix[0].size( );


		while(top < buttom && left < right) {
				int i;
				for(i = left;i<right;++i)
					result.push_back(matrix[top][i]);
				++top;

				if(top == buttom)
					break;

				for(i = top;i<buttom;++i)
					result.push_back(matrix[i][right-1]);
				--right;

				if(right == left)
					break;

				for(i = right;i>left;--i)
					result.push_back(matrix[buttom-1][i-1]);
				--buttom;

				if(buttom == top)
					break;

				for(i = buttom;i>top;--i)
					result.push_back(matrix[i-1][left]);
				++left;

				if(left == right)
					break;
			
		}
		
		return result;
}

int main( ) {
	vector<int> v;
	vector<vector<int> >matrix(4);
	int j = 1;
	int end = 5;
	for(int i=0;i<4;++i){
		for(;j<end;++j){
			matrix[i].push_back(j);
		}
		end += 4;
	}

	Solution s;
	v = s.printMatrix(matrix);
	for(vector<int>::iterator i = v.begin();i!=v.end();++i)
		cout<<*i<<"    ";

	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j)
			cout<<setw(4)<<matrix[i][j]<<"     ";
		cout<<endl;
	}

	system("pause");
	return 0;
}