#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long InversePairs(vector<int> data);
    long InversePairsCore(vector<int>& data,int* copy,long start,long end);
};

 long Solution::InversePairsCore(vector<int>& data,int* copy,long start,long end){
     if(start == end){                    //终止条件
         copy[start] = data[start];
         return 0;
     }
     
     long length = (end-start)/2;
     
     long left = InversePairsCore(data,copy,start,start+length);
     long right = InversePairsCore(data,copy,start+length+1,end);
     
     long i = start+length;                //i指向前半段最后一个元素
     long j = end;
     
     long indexCopy = end;
     long count = 0;
     
     while(i >= start && j >= start+length+1) {
         if(data[i] > data[j]){
           copy[indexCopy--] = data[i--];
             count += j-start-length;
         }
         else{
             copy[indexCopy--] = data[j--];
         }
         
     }
     
     for(;i >= start;--i)
         copy[indexCopy--] = data[i];
     for(;j>=start+length+1;--j)
         copy[indexCopy--] = data[j];

	 for(int k=start;k<=end;++k){            //注意回写
		 data[k] = copy[k];
		// cout<<data[k]<<"  ";
	 }
	 
	 //cout<<endl;

     return  (count + left + right)% 1000000007;
 }

 long Solution::InversePairs(vector<int> data) {
	if(data.empty())
        return 0;
     long length = data.size();
     
     int* copy = new int[length];
     //for(int i=0;i<length;++i){             //拷贝
     //    copy[i] = data[i];
     //}
     
     long count = InversePairsCore(data,copy,0,length-1);
     
     delete[] copy;
     return count ;
 }
int main( ) {
	vector<int> v;
	v.push_back(7);
	v.push_back(5);
	v.push_back(6);
	v.push_back(4);
	Solution s;
	int result = s.InversePairs(v);
	cout<<result<<endl;
	system("pause");
	return 0;
}