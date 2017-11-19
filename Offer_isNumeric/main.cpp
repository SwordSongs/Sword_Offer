#include<iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string);
    void scanDigits(char*& string);
    bool isExponential(char*& string);

};

void Solution::scanDigits(char*& string){
    while(*string != '\0' && *string >= '0' && *string <= '9'){
        ++string;
    }
}

bool Solution::isExponential(char*& string){
	++string;
    if(*string == '+' || *string == '-')
        ++string;
    if(*string == '\0')
        return false;
    scanDigits(string);
    return (*string == '\0') ? true : false;
}


bool Solution::isNumeric(char* string) {
    if(string == NULL)
        return false;
    if(*string == '+' || *string == '-')
        ++string;
    if(*string == '\0')
        return false;
    
    bool numeric = true;
    scanDigits(string);
    
    if(*string != '\0'){
        //for float
        if(*string == '.'){
            ++string;
            scanDigits(string);
			if(*string == 'e' || *string == 'E'){
					numeric = isExponential(string);
			}
        } //for integer
       else if(*string == 'e' || *string == 'E'){
    		numeric = isExponential(string);    
		}
		 else{
			 numeric = false;
		} 

    }         
    return numeric && *string == '\0';
}

int main( ) {
	Solution s;
	char* str = "100";
	 bool b = s.isNumeric(str);
	 cout<<"b = "<<b<<endl;

	system("pause");
	return 0;
}