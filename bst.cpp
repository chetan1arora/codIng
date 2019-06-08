#include <iostream>

class node{
public:
	int data;
	node *left = NULL;
	node *right = NULL;
	node(int data){
		this->data = data;
	}
}

void showINorder(node *root);

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
	showINorder(head);
	cout<<endl;



	return 0; // Success
}


// INorder Recursion

void showINorder(node* root){
	if(root->left == NULL)
		cout<<root->data<<" ";
	else
		showINorder(root->left);

	if(root->right != NULL)
		showINorder(root->right);

	return;

} // Need extra endline to cout
 
