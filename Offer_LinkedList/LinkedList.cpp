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