#include <iostream>
#include <map>
#include <iterator>
#include <queue>
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
		this->right = NULL;

	};
};


void levelOrder(node *root){
	node* current = root;
	pair<node*,int> temp;
	queue< pair<node*,int> > levelOrderQueue;
	int dir = 0;
	levelOrderQueue.push(pair<node*,int>(current,dir));
	
	map<int,int> treeMap;


	while(levelOrderQueue.empty() != true){
		temp = levelOrderQueue.front();
		
		current = temp.first;
		dir = temp.second;

		treeMap[dir] = current->data;

		if(current->left != NULL)
			levelOrderQueue.push(pair<node*,int>(current->left,dir-1));
		if(current->right != NULL)
			levelOrderQueue.push(pair<node*,int>(current->right,dir+1));

		levelOrderQueue.pop();
	} 

	map<int,int>::iterator itr;
	itr = treeMap.begin();
	for(;itr != treeMap.end();itr++)
		cout<<itr->second<<" ";

	cout<<endl;


	return;
}



int main(int argc, char const *argv[])
{
	node* root = new node(20);
	root->left = new node(30);
	root->right = new node(40);
	root->left->left = new node(60);
	root->left->right = new node(70);

	levelOrder(root);


	return 0;
}