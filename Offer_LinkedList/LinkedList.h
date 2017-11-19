#pragma once
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
	private:
		LinkedNode* first;
};