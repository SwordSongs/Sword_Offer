#include<iostream>
#include"LinkedList.h"
using namespace std;

int main( ) {
	LinkedList *L = new LinkedList( );
	L->Add(1);
	L->Add(2);
	L->Add(3);
	L->Add(4);
	L->output( );
	cout<<endl;
	LinkedNode * p = L->getfirst( );
	L->reverseOutput(p);
	
	system("pause");
	return 0;
}