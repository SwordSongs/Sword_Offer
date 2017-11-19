#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV);
};

bool Solution::IsPopOrder(vector<int> pushV,vector<int> popV) {
    bool b = false;
	stack<int> s;
	if(pushV.size( ) != 0 && popV.size( ) != 0) {
		for(int i=0,j=0;i<pushV.size();++i){
			s.push(pushV[i]);
			while(j < popV.size( ) && s.top( ) == popV[j]){
				s.pop( );
				++j;
			}
		}
		if(s.empty( ))
			b = true;
		else
			b = false;
	}
	return b;
}



int main( ) {
	Solution s;
	vector<int> v1;
	vector<int> v2;
	bool b = false;

	for(int i=1;i<6;++i)
		v1.push_back(i);

	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);

	b = s.IsPopOrder(v1,v2);
	if(b)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	system("pause");
	return 0;
}