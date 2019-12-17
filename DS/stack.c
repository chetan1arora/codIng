#include <stdlib.h>
#include <stdbool.h>

// Stack Implementation
//Using Data Nodes
struct node{
	int data;
	node* prev;

};

class stack{
private:
	int count;
	node* head;
public:		
	stack(){
		this.count = 0;
		head = NULL;
	}
	void push(int data){
		node* temp = (node*) malloc(sizeof(node));
		temp->data = data;
		temp->prev = head;
		this.head = temp;
		
		this.count++;
		return;
	}
	int top(){
		return head->data;
	}
	void pop(){
		this.head = this.head->prev;
		this.count--;
		return;
	}
	int size(){
		return count;
	}
	bool empty(){
		if(count == 0){
			return true;
		}
		return false;
	}
};