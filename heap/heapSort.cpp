#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
using namespace std;

class node{

public:
	int data;
	int index
	node* right;
	node* left;
	node(int data,int index){
		this->data = data;
		this->index = index;
		this->left = NULL;
		this->right = NULL;
	}
};


node* makeHeap(int * arr,int size){

	queue< node* > levelQ;
	node* root = new node(arr[0],0);
	levelQ.push(root);

	node* temp;
	int count = 1;
	while(count != size){
		temp = levelQ.front();
		levelQ.pop();
		temp->left = new node(arr[count],count);
		count++;
		if(count == size){
			break;
		}
		temp->right = new node(arr[count],count);
		count++; 
		levelQ.push(temp->left);
		levelQ.push(temp->right);
	}

	return root;

}




void heapSort(int* arr, int size){

	// Make heap
	node* root = makeHeap(vect);

	// Heapify Procedure
	root = heapify(root,arr);


}