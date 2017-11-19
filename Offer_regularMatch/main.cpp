#include<iostream>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern);
    bool matchCore(char* str, char* pattern);
};

bool Solution::match(char* str, char* pattern) {
    if(str == NULL && pattern == NULL)           //特殊测试用例
        return true;
    if(str == NULL || pattern == NULL)
        return false;
    
    return matchCore(str,pattern);
}

bool Solution::matchCore(char* str, char* pattern) {
    if(*str == '\0' && *pattern == '\0')        //特殊用例
        return true;
    if(*str != '\0' && *pattern == '\0')
        return false;
        
    if(*(pattern+1) == '*'){               //处理pattern中存在*的情况
        if(*pattern == *str || (*pattern == '.' && *str != '\0')){    //匹配成功
            return matchCore(str+1,pattern+2) || matchCore(str+1,pattern) || matchCore(str,pattern+2);
            //     1.move on the next state       2.stay on the current state           3.ignore a '*'
        }
        else{  //匹配失败，可以忽略‘*’
            return matchCore(str,pattern+2);   //ignore a '*'
        }
    }

	    if(*str == *pattern ||(*pattern == '.' && *str != '\0'))   //匹配成功情况
					 return matchCore(str+1 , pattern+1);
    
    return false;
    
}


int main( ) {
	Solution s;
	char* str = "a";
	char* p = ".*";
	//char * g = "hello";
	//g[0] = 'H';
	//cout<<g<<endl;

	bool b = s.match(str,p);
	cout<< "b = " <<b<<endl;

	system("pause");
	return 0;
}
