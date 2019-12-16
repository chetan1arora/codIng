
// Making a Graph data structure 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Will use adjacent list

void insertEdge(list< int > * arr,int a, int b){
	arr[a].push_back(b);
	return;
}


// Depth First Search
void printDFS(list< int > * adjList,int start){
	int size = adjList->size();
	bool visited[size] = {false}; 
	int temp;
	visited[start] = true;


	list< int > dfs;

	std::stack< int > memory;
	memory.push(start);

	cout<<"Dfs :"<<endl;
	cout<<start<<" ";
	
	std::list< int >::iterator itr;
	while(memory.empty() != true){
		// Print the element
		temp = memory.top();

		if(dfs.size() == size){
			break;
		}
		itr = adjList[temp].begin();
		for(;itr != adjList[temp].end();++itr){
			if(visited[*itr] != true){
				// Push it and continue
				visited[*itr]= true;
				cout<<*itr<<" "; 
				memory.push(*itr);
				break;
			}
		}
		if(itr == adjList[temp].end()){
			memory.pop();
		}

	}
	cout<<endl;
}


int main(){

	int nodes = 4;
	list< int > * adjList = new list< int >[nodes];


	insertEdge(adjList,0, 1); 
    insertEdge(adjList,0, 2); 
    insertEdge(adjList,1, 2); 
    insertEdge(adjList,2, 0); 
    insertEdge(adjList,2, 3); 
    insertEdge(adjList,3, 3); 
  
   	printDFS(adjList,2);  

   	return 0;

}