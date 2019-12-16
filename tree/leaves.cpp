#include <iostream>

using namespace std;

class node
{
public:
	node* prev;
	node* next;
	int data;
	node(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	};
};



node* remove_node(node* head,int data){
	node* current = head;
	if(head == NULL){
		return NULL;
	}

	while(current->data != data && current->next != head){
		current = current->next;
	}
	if(current->data == data){
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}
	else
		return head; // No element found

	if(current == head)
		return current->next; // If head is the element
	return head;
}

node* add_node(node* head,int data){
	node* current = head;
	node* temp;
	if(head == NULL){
		temp  = new node(data);
		temp->next = temp;
		temp->prev = temp;
		return temp; 
	}

	while(current->data != data && current->next != head){
		current = current->next;
	}
	if(current->next == head){ // Element not found
		temp = new node(data);
		temp->next = head;
		temp->prev = head->prev;
		temp->prev->next = temp;
		temp->next->prev = temp;
		return temp;
	}
	else
		return head;
}

int count(node* head){
	node* current = head;
	int count=1;
	if(current ==NULL)  // Hypothetical case
		return 0;

	while(current->next != head){
		current = current->next;
		count++;
	}

	// Print linklist
	node* temp;
	temp = head;
	cout<<"current element is "<<temp->data<<endl;
	while(temp->next != head){
		temp = temp->next;
		cout<<"current element is "<<temp->data<<endl;
	}

	return count;
}


int main()
{
	int T,edges;
	cin>>T;
	int a,b;
	char temp;
	node* head ;
	while(T--){
		cin>>edges;
		head = NULL; // New List for each case
		while(edges--){
			cin>>a;
			cin>>b;
			cin>>temp;
			head = remove_node(head,a);
			//cout<<"rem_done"<<endl;
			head = add_node(head,b);
			//cout<<"add_done"<<endl;
		//	cout<<"head is "<<head->data<<endl;
		}
		
		cout<<"Number of leaves: "<<count(head)<<endl;
	}
	return 0;
}