#include <iostream>
#include <stack>

using namespace std;

class node{
public:
	int data;
	node *left = NULL;
	node *right = NULL;
	node(int data){
		this->data = data;
	}
};


// Recursive approach

node * makeMYtree(node * head,int new_data){

	if(head == NULL){
		return new node(new_data);
	}

	if(head->data > new_data)
		head->left = makeMYtree(head->left,new_data);
	else if(head->data < new_data)
		head->right = makeMYtree(head->right,new_data);

	//else do nothing

	return head; // Success
}

void showinOrderWithStack(node * root){

	stack<node*> s;
	node *temp;
	s.push(root);
	while(s.top() != NULL){

		if(s.top()->left != NULL){
			s.push(s.top()->left);
			continue;
		}
		while(s.top()->right == NULL){
			cout<<s.top()->data<<" ";
			s.pop();
		}
		temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		s.push(temp->right);
	}

	cout<<endl;
}

int main()
{
	
	node *head = NULL;
	int N,data;
	cin>>N;
	while(N--){
		cin>>data;
		head = makeMYtree(head,data);
	}
	
	// Printing
	showinOrderWithStack(head);
	cout<<endl;



	return 0; // Success
}
