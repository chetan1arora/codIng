#include <iostream>
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

	}
};


void count(node* root,int* cnt,int k){
	if(root->left != NULL)
		count(root->left,cnt,k);

	*(cnt) = *(cnt)+1;
	if(*(cnt) == k){
		cout<<root->data<<endl;
		return;
	}

	if(root->right != NULL)
		count(root->right,cnt,k);

	return;
}



int main(int argc, char const *argv[])
{
	node* root = new node(10); 
    root->left = new node(20); 
    root->right = new node(30); 
    root->left->left = new node(40); 
    root->left->right = new node(50); 
	
	int *cnt = new int(0);

    count(root,cnt,3);

	return 0;
}

