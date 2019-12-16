#include <iostream>
#include <list>
using namespace std;

class node{

public:
	int data;
	node* left;
	node* right;
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;

	};
};

void inorderTree(node* root,list<int> &inorder){
	if(root->left != NULL)
		inorderTree(root->left,inorder);

	inorder.push_back(root->data);

	if(root->right != NULL)
		inorderTree(root->right,inorder);

	return;
}

node* manipulateTree(node* root,list<int> &inorder){
	if(root->left != NULL)
		root->left = manipulateTree(root->left,inorder);

	root->data = inorder.front();
	inorder.pop_front();

	if(root->right != NULL)
		root->right = manipulateTree(root->right,inorder);

	return root;
}



node* treeToBST(node* root){
	// Inorder traversal of tree
	list<int> inorder;

	inorderTree(root,inorder);

	inorder.sort();

	return manipulateTree(root,inorder);
}

int main()
{
	node* root = new node(10);
	root->left = new node(2);
	root->left->left = new node(8);
	root->left->right = new node(4);

	root->right = new node(7);
	

	root = treeToBST(root);

	cout<<root->data<<" ";
	cout<<root->left->data<<" ";
	cout<<root->left->left->data<<" ";
	cout<<root->left->right->data<<" ";

	cout<<root->right->data<<" ";
	
	cout<<endl;

	return 0;
}