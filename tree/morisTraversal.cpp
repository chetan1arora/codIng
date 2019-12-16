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


void morisTraversal(node* root){
	printf("Hellow\n");
	node* current = root;
	node* temp = NULL;
	while(current != NULL){
		if(current->left == NULL){
			cout<<current<<" ";
			if(current->right != NULL){
				current = current->right;
			}
		}
		else{
			temp = current->left;
			while(temp->right != NULL){
				temp = temp->right
			}
			temp->right = current;
			current = current->left;
		}
	}

	cout<<endl;
	return;
}

int main(int argc, char const *argv[])
{
	node* root = new node(25);
	root->left = new node(23);
	root->right = new node(12);
	root->left->left = new node(43);
	root->left->right = new node(14);
	root->right->left = new node(65);
	root->right->right = new node(34);
	root->left->right->left = new node(97);
	root->left->left->right = new node(24);

	morisTraversal(root);
	return 0;
}



