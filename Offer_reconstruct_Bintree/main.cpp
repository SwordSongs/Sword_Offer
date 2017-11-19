#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main( ) {
	BinaryTree * BTree = new BinaryTree( );
	int preOrder[ ] = {1,2,4,7,3,5,6,8};
	int inOrder[ ] = {4,7,2,1,5,3,8,6};

	/*BinTreeNode * root = BTree->create( );
	BTree->preOrder(root);
	BTree->inOrder(root);*/

	BinTreeNode* root = BTree->reConstruct(preOrder,inOrder,8);
	BTree->preOrder(root);


	system("pause");
	return 0;
}