#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

class BinaryTree{
	public:
		TreeNode* create( );
		void preOrder(TreeNode* root);
	private:
		TreeNode* root;
};

TreeNode* BinaryTree::create( ) {
	cout<<"ÇëÊäÈëÊý¾Ý£º"<<endl;
	int v;
	TreeNode* t;
	cin>>v;

	if(v == 0 )
		t = NULL;
	else{
		t = new TreeNode(v);
		t->left = create( );
		t->right = create( );
	}
	return t;
}

void BinaryTree::preOrder(TreeNode* root) {
	if(root){
		cout<<root->val<<"   ";
		preOrder(root->left);
		preOrder(root->right);
	}
}




class Solution {
	public:
		void Mirror(TreeNode* pRoot);
};

void Solution::Mirror(TreeNode* pRoot) {
	if(pRoot == NULL)
		return;
	if(pRoot->left == NULL && pRoot->right == NULL)
		return;

	TreeNode* temp;
	temp = pRoot->right;
	pRoot->right = pRoot->left;
	pRoot->left = temp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}


int main( ) {
	BinaryTree t;
	TreeNode * root;
	root = t.create( );
	t.preOrder(root);
	cout<<endl;
	Solution s;
	s.Mirror(root);
	t.preOrder(root);
	
	

	system("pause");
	return 0;
}