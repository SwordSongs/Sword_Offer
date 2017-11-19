#include<iostream>
#include"BinaryTree.h"
using namespace std;

BinTreeNode* BinaryTree::create( ) {
			BinTreeNode* t;
			char data = 0;
			cout<<"����������: "<<endl;
			cin>>data;
			if(data == '#')
				t = NULL;
			else{
				t = new BinTreeNode(data);
				t->leftchild = create( );
				t->rightchild = create( );
			}		
			return t;
		}

BinTreeNode* BinaryTree::preOrder(BinTreeNode* p) {
	if(p){
		cout<<p->data<<" ";
		preOrder(p->leftchild);
		preOrder(p->rightchild);
	}
	return p;
}

BinTreeNode* BinaryTree::inOrder(BinTreeNode* p) {
		if(p){
			preOrder(p->leftchild);
			cout<<p->data<<" ";
			preOrder(p->rightchild);
	}
	return p;

}

BinTreeNode* BinaryTree::reConstruct(int *preOrder,int *inOrder,int length) {
	if(preOrder == NULL || inOrder == NULL || length <= 0)
		return  NULL;
	return reConstructcore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
}

BinTreeNode* BinaryTree::reConstructcore(int * startPreOrder,int * endPreOrder,int * startInOrder,int *endInOrder) {
	int rootValue = startPreOrder[0];
	BinTreeNode * root = new BinTreeNode(rootValue);

	if(startPreOrder == endPreOrder) {           //������һ��Ԫ�����
		if(startInOrder == endInOrder && *startPreOrder == *endInOrder){
			return root;
		}
		else{
			throw std::exception("Invalid input.");
		}
	}

		//��������ҵ����ڵ�
		int * rootInOrder = startInOrder;
		while(rootInOrder <= endInOrder &&  *rootInOrder != rootValue)
			++rootInOrder;
		if(rootInOrder <= endInOrder && *rootInOrder != rootValue)
			throw std::exception("Invalid input.");

		int leftLength = rootInOrder - startInOrder;
		int *leftPreOrderEnd = startPreOrder + leftLength;

		if(leftLength > 0) {
			//����������
			root->leftchild = reConstructcore(startPreOrder+1,leftPreOrderEnd,startInOrder,rootInOrder-1);
		}

		if(leftLength < endInOrder - startInOrder){
			//����������
			root->rightchild = reConstructcore(leftPreOrderEnd+1,endPreOrder,rootInOrder+1,endInOrder);
		}
		return root;
	

}
