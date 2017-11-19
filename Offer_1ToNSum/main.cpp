#include<iostream>
using namespace std;

class A;
A* Array[2];

class A{
public:
	virtual int sum (unsigned int n){
		return 0;
	}
};

class B : public A {
public:
	int sum(unsigned int n){
		return Array[!!n]->sum(n-1) + n;
	}
};


int main( ) {
	A a;
	B b;

	Array[0] = &a;
	Array[1] = &b;         //一个绑定父类对象，一个绑定子类对象

	int value = Array[1]->sum(100);
	cout<<value<<endl;
	system("pause");
	return 0;
}