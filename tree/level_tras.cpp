#include <iostream>

using namespace std

class node
{
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


void printLevel(node* root, int level){

	if(root == NULL)
		return ;
	if(level == 0)
		cout<<root->data<<" ";
	else if(level>0){
		if(root->left != NULL)
			printLevel(root->left,level-1);
		if(root->right != NULL)
			printLevel(root->right,level-1);
	}
	return;
}

int tree_len(node* root){
	
	if(root->left == NULL && root->right == NULL)
		return 1;
	else if(root->left != NULL && root->right != NULL)
		return 1+max(tree_len(root->left),tree_len(root->right));
	else if(root->left != NULL && root->right == NULL)
		return 1+tree_len(root->left);
	else if(root->left == NULL && root->right != NULL)
		return 1+tree_len(root->right);
}

int main(){

	node* root = new node(20);
	root->left = new node(30);
	root->right = new node(40);
	root->left->left = new node(50);
	root->left->right = new node(60);

	int len = tree_len(root);

	cout<<"Length of tree: "<<len<<endl;
	for(int i=0;i<len;i++){
		printLevel(root,i);
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
