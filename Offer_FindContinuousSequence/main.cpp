#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum);
};

vector<vector<int> > Solution::FindContinuousSequence(int sum){
    vector<vector<int> > result;
    vector<int> v;
    
    if(sum < 3)                 //从1，2开始，且是连续正数
        return result;
	
    int first = 1;
    int last = 2;
    int mid = (1+sum) >> 1;     //first到mid为止
    int curSum = first+last;
    
    v.push_back(first);
    v.push_back(last);
    
    while(first < mid){
		if(curSum == sum){
            result.push_back(v);
        }
        
        
		while(curSum > sum && first < mid){
            curSum -= first++;
            v.erase(v.begin());
            
            if(curSum == sum)
                result.push_back(v);
        }
        
        ++last;
        curSum += last;
        v.push_back(last);
         
    }
    
    
   return result; 
}



int main( ) {
	Solution s;
	vector<vector<int> > result =  	s.FindContinuousSequence(15);

	for(vector<vector<int> >::iterator i = result.begin();i!=result.end();++i){
		vector<int> a((*i).begin(),(*i).end());
		for(vector<int>::iterator j=a.begin();j!=a.end();++j){
			cout<<*j<<"   ";
		}
		cout<<endl;
	}
		
	system("pause");
	return 0;
}