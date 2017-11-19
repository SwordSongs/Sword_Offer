#pragma once
#include"LinkedList.h"
#include<iostream>

bool LinkedList::Add(int value) {
	LinkedNode *p = new LinkedNode(value);
	if(first == NULL){
		first = p;
		return true;
	}
	else {
		p->next = first;
		first = p;
		return true;
	}
}

bool LinkedList::remove(int value) {
	if(first == NULL)
		return false;
	LinkedNode * p = NULL;
	LinkedNode *q = NULL;

	if(first->data == value){
		p = first;
		first = first->next;
	}
	else {
		p = first;
		while(p->next != NULL&&p->data != value){
			q= p;
			p = p->next;
		}
		if(p->next == NULL&&p->data != value)
			return false;
		if(p->data == value) {
			q->next = p->next;
		}

		if(p) {
			delete p;
			p = NULL;
			return true;
		}
	}	
}

void LinkedList::output( ) {
	LinkedNode *current = first;
	while(current !=  NULL){
		std::cout<<current->data<<" ";
		current = current->next;
	}
}

LinkedNode* LinkedList::getfirst( ) {
	return first;
}

//注意reverseOutput不要写到LinkedList.h中，防止包含文件时重复定义
/*void reverseOutput(LinkedList* &L) {
	std::stack<LinkedNode*> S;
	LinkedNode* p;
	p = L->first;
	while(p != NULL) {
		S.push(p);
		p = p->next;
	}
	
	while(!S.empty( )) {
		p = S.top( );
		std::cout<<p->data<<" ";
		S.pop( );
	}
}  */    

/*void LinkedList::reverseOutput(LinkedList* &L) {
	std::stack<LinkedNode*> S;
	LinkedNode* p;
	p = L->first;
	while(p != NULL) {
		S.push(p);
		p = p->next;
	}
	
	while(!S.empty( )) {
		p = S.top( );
		std::cout<<p->data<<" ";
		S.pop( );
	}
}*/






void LinkedList::reverseOutput(LinkedNode* &p) {
	if(p != NULL) {
		if(p->next != NULL) {
			reverseOutput(p->next);    //recursion
		}
		std::cout<<p->data<<" ";    //print
	}
}