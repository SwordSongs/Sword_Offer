#include<iostream>
#include<stack>
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
		void inOrder(TreeNode* root);
		void inOrder2(TreeNode* root);
	private:
		TreeNode* root;
		stack<TreeNode*> s;
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

void BinaryTree::inOrder(TreeNode* root) {
	if(root) {
		inOrder(root->left);
		cout<<root->val<<"   ";
		inOrder(root->right);
	}
}

void BinaryTree::inOrder2(TreeNode* root) {
	TreeNode * p = root;
	while(p != NULL || !s.empty() ) {
			while(p != NULL) {
				s.push(p);
				p = p->left;
			}

			if(!s.empty( )) {
				p = s.top( );
				cout<<p->val<<"    ";
				s.pop( );
				p = p->right;
			}
	}
}

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree);
private:
	stack<TreeNode*> s;

};


TreeNode* Solution::Convert(TreeNode* pRootOfTree) {
	TreeNode * p = pRootOfTree;
	TreeNode *pre = pRootOfTree;
	TreeNode *root = NULL;
	if(pRootOfTree == NULL)
		return NULL;

	bool isFirst = true;
	while(p != NULL || !s.empty() ) {
			while(p != NULL) {
				s.push(p);
				p = p->left;
			}

			if(!s.empty( )) {
				p = s.top( );
				s.pop( );

				if(isFirst){
					root = p;
					pre = root;
					isFirst = false;
				}
				else {
					pre->right = p;
					p->left = pre;
					pre = p;
				}
				p = p->right;
			}
	}
		return root;
}




int main( ) {
	BinaryTree tree;
	TreeNode * root = tree.create( );
	tree.preOrder(root);
	cout<<endl;
	tree.inOrder2(root);
	//Solution s;
	//s.Convert(root);
	system("pause");
	return 0;
}