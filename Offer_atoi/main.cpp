#include<iostream>
using namespace std;

enum Status {kVaild=0,kInvaild};
enum Status g_Status = kVaild;
class Solution {
public:
    int StrToInt(string str);
    long long StrToIntCore(char* str1,bool minus);
};

int Solution::StrToInt(string str) {
 	g_Status = kInvaild;
 	long long num = 0;
    
    char *str1 = NULL;               //拷贝副本
    int len = str.length( );
    str1 = new char[len+1];
    strcpy(str1,str.c_str());
    str1[len] = '\0';
    
    if(str1 != NULL && *str1 != '\0'){
        bool minus = false;
        if(*str1 == '+'){
            str1++;
        }else if(*str1 == '-'){
            str1++;
            minus = true;
        }
        
        if(*str1 != '\0'){
            num = StrToIntCore(str1,minus);
        }   
        
    }
    
    return static_cast<int>(num);
}

long long Solution::StrToIntCore(char* str1,bool minus){
    long long num = 0;
    while(*str1 != '\0'){
        if(*str1 >= '0' && *str1 <= '9'){
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*str1 - '0');
            
            if((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)){  //范围检查
                num = 0;
                break;
            }
            
            ++str1;
        }
        else{                   //不是数字
        	num = 0;
            break;
        }
        
    }
    
    if(*str1 == '\0'){            //如果字符串为“”，置全局变量，并且返回0
        g_Status = kInvaild;
    }
    return num;
}


int main( ) {
	string s = "-123";
	Solution so;
	int i = so.StrToInt(s);
	cout<<i<<endl;
	system("pause");
	return 0;
}