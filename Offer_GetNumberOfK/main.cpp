#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k);
    int GetFirst(vector<int> data,int k,int start,int end);
    int GetLast(vector<int> data,int k,int start,int end);
};

int Solution::GetNumberOfK(vector<int> data ,int k){
    if(data.empty())
        return 0;
    int length = data.size();
    int first = GetFirst(data,k,0,length-1);
    int last = GetLast(data,k,0,length-1);

	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
    
    int result = 0;
    if(first >= 0 && last >= 0)
    	 result = last-first+1;
    return result;
}

int Solution::GetFirst(vector<int> data,int k,int start,int end){
    if(start > end)
        return -1;
    
    int mid = (start+end)/2;
    if(data[mid] == k){
        if(mid > 0 && data[mid-1] != k || mid == 0)         //判断是不是第一个k
            return mid;
        else
            end = mid-1;
    }
    else if(data[mid] > k){
        end = mid-1;
    }
    else{
    	start = mid+1;    
    }
    
    return GetFirst(data,k,start,end);
    
}

int Solution::GetLast(vector<int> data,int k,int start,int end){
    if(start > end)
        return -1;
    int mid = (start+end)/2;
    if(data[mid] == k){
        if(mid < data.size()-1 && data[mid+1] != k || mid == data.size()-1)
            return mid;
        else
            start = mid+1;      
    }
    else if(data[mid] > k){
        end = mid-1;
    }
    else{
        start = mid+1;
    }
    
    return GetLast(data,k,start,end);
}

int main( ) {
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	int result = s.GetNumberOfK(v,2);
	cout<<"result = "<<result<<endl;


	system("pause");
	return 0;
}