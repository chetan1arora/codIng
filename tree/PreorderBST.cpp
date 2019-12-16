#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	};
};


node* BSTfromPreorder(vector<int> &preorder){
	stack< node* > myStack;
	node* root = new node(preorder.front());
	myStack.push(root);
	node* temp;
	for(auto it= preorder.begin()+1; it != preorder.end(); ++it){
		if(*it < myStack.top()->data){
			temp = myStack.top();
			temp->left = new node(*it);
			myStack.push(temp->left);
		}
		else{
			// *it > myStack.top()
			temp = myStack.top();
			myStack.pop();
			while(!myStack.empty() && myStack.top()->data < *it){
				temp = myStack.top();
				myStack.pop();
			}
			// new element should add to temp->right
			temp->right = new node(*it);
			myStack.push(temp->right);
		}
	}
	return root;
}

int main(int argc, char const *argv[])
{
	vector<int > preorder;
	int N,temp;
	cin>>N;
	while(N--){
		cin>>temp;
		preorder.push_back(temp);
	}

	node* root = BSTfromPreorder(preorder); 

	// Testing
	cout<<root->right->data<<" ";
	cout<<root->left->right->data<<" ";
	cout<<root->right->right->data<<" ";
	cout<<root->data<<" ";

	cout<<endl;
	return 0;
}