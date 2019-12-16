#include <iostream>

using namespace std;


class node
{
public:
	node* left;
	node* right;
	int data;
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	};
};


node* insertNode(node* head,int data){

	if(head == NULL){
		return new node(data);
	}

	node* current = head;
	while(1){
		if(current->data > data){
			
			if(current->left != NULL)
				current = current->left;
			else{
				current->left = new node(data);
				return head;
			}
		}
		else if(current->data < data){
			
			if(current->right != NULL)
				current = current->right;
			else{
				current->right = new node(data);
				return head;
			}
		}
		else
			return head;
	
	}

}


int main(int argc, char const *argv[])
{
	node* head;
	head = insertNode(head,25);
	head = insertNode(head,35);
head = insertNode(head,25);
head = insertNode(head,45);
head = insertNode(head,65);
head = insertNode(head,15);
head = insertNode(head,67);
head = insertNode(head,2);
	
	return 0;
}