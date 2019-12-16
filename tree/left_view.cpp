#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right= NULL;
	};
	
};

void left_view(node* root){

	if(root == NULL){
		cout<<"No data"<<endl;
		return;
	}
	cout<<root->data<<" ";

	if(root->left != NULL)
		left_view(root->left);

	else if(root->right != NULL)
		left_view(root->right);
	
	else
		return;
}


int main()
{
	node* root = new node(20);
	root->left = new node(30);
	root->right = new node(40);
	root->left->left = new node(50);
	root->left->right = new node(60);

	left_view(root);
	cout<<endl;
	return 0;
}
