#include <iostream>
using namespace std;

struct BinTreeNode {
	BinTreeNode* leftchild;
	BinTreeNode* rightchild;
	char data;
	BinTreeNode(char d) {
		leftchild = NULL;
		rightchild = NULL;
		data = d;
	}
	~BinTreeNode( ) {
	
	} 
};

class BinaryTree {
	public:
		BinaryTree( ) {
			root = NULL;
		}
		BinaryTree(char d) {
			root = new BinTreeNode(d);
		}
		BinTreeNode* create( );
		BinTreeNode* preOrder(BinTreeNode* p);
		BinTreeNode* inOrder(BinTreeNode* p);
		BinTreeNode* reConstruct(int *preOrder,int *inOrder,int length);
		BinTreeNode* reConstructcore(int * startPreOrder,int * endPreOrder,int * startInOrder,int *endInOrder);
	private:
		BinTreeNode* root;

};