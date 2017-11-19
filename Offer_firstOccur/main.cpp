#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str);
};

int Solution::FirstNotRepeatingChar(string str) {
    if(str == "")
        return -1;                    //处理为空情况

	int length = str.length( );
    
 	int  hash[52] = {0};              //A--Z  a--z
    int i=0;
   
    while(i < length){
        if(str[i]>='a'&&str[i]<='z'){  //0--25
						hash[str[i] - 'a'] += 1;
            }
            
        
         if(str[i]>='A'&&str[i]<='Z'){  //27--51
            hash[str[i] - 'A'+26] += 1;   
        }
        ++i;
    }  

	char c;

	for(int i=0;i<length;++i) {
		 c = str[i];
		 if(c >= 'a' && c <= 'z' ){
				if(hash[c - 'a']  == 1)
					return i;
		 }
		 else if(c >= 'A' && c <= 'Z' ){
				if(hash[c - 'A' + 26]  == 1)
					return i;
		 }
	}

	return -1;

}



int main( ) {
	Solution s;
	int result =   s.FirstNotRepeatingChar("NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp");

	cout<<result<<endl;

	system("pause");
	return 0;
}