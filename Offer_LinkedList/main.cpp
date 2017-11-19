#include<iostream>
#include"LinkedList.h"
using namespace std;

int main( ) {
	LinkedList *L = new LinkedList( );
	L->Add(1);
	L->Add(2);
	L->Add(3);
	L->remove(1);
	L->remove(3);
	L->output( );

	system("pause");
	return 0;
}