#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
using namespace std;

class node
{
public:
	stack <node *> children;
	node* parent;
	pair < int,int > loc;
	node(int i,int j,node* parent){
		this->loc.first = i;
		this->loc.second = j;
		this->parent = parent; 
	};
	
};




bool check_limit(int x,int y){
	if((x >= 0) && (x < 8) && (y >= 0) && (y < 8))
		return true;
	return false;
}


int travel(vector< pair< int , int > > &path, node* root){

	path.push_back(root->loc);
	// Make childs
	int i=root->loc.first,j= root->loc.second;
	
	int success;
	pair < int,int > child;

	// Shortcut
	if(path.size() == 64)
		return 0; //Success 

	bool found = false;

	/*
	* Possiblilities of going ahead 
	*/
	std::vector< pair< int,int > >::reverse_iterator ritr;


	if(check_limit(i+2,j+1)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i+2 && ritr->second == j+1){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i+2,j+1,root));
		}
	}

	found = false;

	if(check_limit(i+1,j+2)){

		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i+1 && ritr->second == j+2){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i+1,j+2,root));
		}
	}	

	found = false;


	if(check_limit(i-2,j-1)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i-2 && ritr->second == j-2){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i-2,j-1,root));
		}
	}

	found = false;


	if(check_limit(i-1,j-2)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i-1 && ritr->second == j-2){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i-1,j-2,root));
		}
	}


	found = false;

	if(check_limit(i+2,j-1)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i+2 && ritr->second == j-1){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i+2,j-1,root));
		}
	}



	found = false;

	if(check_limit(i-2,j+1)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i-2 && ritr->second == j+1){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i-2,j+1,root));
		}
	}


	found = false;

	if(check_limit(i-1,j+2)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i-1 && ritr->second == j+2){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i-1,j+2,root));
		}
	}

	found = false;

	if(check_limit(i+1,j-2)){
		ritr = path.rbegin();
		
		for(;ritr != path.rend(); ++ritr){
			if(ritr->first == i+1 && ritr->second == j-2){
				//cout<<"Nope"<<endl; 
				found = true; 
				break;
			}
		}

		if(found == false){
			root->children.push(new node(i+1,j-2,root));
		}
	}

	found = false;

	while(root->children.empty() != true){
		success = travel(path,root->children.top());   /// Somethings i m not sure of 
			if(success == 0){
				return 0;

			} else{
				root->children.pop();
			}
	}

	// Not a good path
	path.pop_back(); // Achieved same state
	

	// // Debugging
	// std::vector< pair < int,int > >::iterator itr;
	// itr = path.begin();
	// for(;itr != path.end(); ++itr ){
	// 	cout<<"("<<itr->first <<","<<itr->second<<") " ;
	// }
	// cout<<endl;

	//cout<<path.size()<<endl;

	return -1;

}

int main()
{

	node* root = new node(0,0,NULL);
	vector< pair< int,int > > path;
	travel(path,root);
	std::vector< pair < int,int > >::iterator itr;
	itr = path.begin();
	cout<<"Knight takes: "<<endl;
	for(;itr != path.end(); ++itr ){
		cout<<"("<<itr->first <<","<<itr->second<<") " ;
	}
	cout<<endl;

	return 0;
}	