#include<stack>
#include<iostream>

struct LinkedNode {
	int data;
	 LinkedNode* next;
	 LinkedNode(const int item,LinkedNode* p = NULL) {
		data = item;
		next = p;
	 }
};

class LinkedList {

	public:
		LinkedList( ) {
			first = NULL;
		}
		~LinkedList( ) {
		}
		bool Add(int value);
		bool remove(int value);
		void output( );
		LinkedNode* getfirst( );
	    //friend void reverseOutput(LinkedList* &L);
		void reverseOutput(LinkedNode* &p);
		
	private:
		LinkedNode* first;
};

