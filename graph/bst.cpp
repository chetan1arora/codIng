#include <iostream>
#include <iterator>
#include <vector>
#include <queue>

using namespace std;

// Will use adjacent list

void insertEdge(vector< int > * arr,int a, int b){
	arr[a].push_back(b);
	return;
}


// Print Breadth first Order using Queue

void printBFS(vector< int > *arr,int nodes,int start){

	// Starting with element 0 as root
	bool visited[nodes] = {false};
	visited[start] = true;
	std::queue< int > levelQ;
	levelQ.push(start);
	int temp;
	std::vector< int >::iterator itr;
	
	while(levelQ.empty() != true){
		temp = levelQ.front();
		levelQ.pop();
		itr = arr[temp].begin();

		for(;itr != arr[temp].end();++itr){	
			if(visited[*itr] == false){
				visited[*itr] = true;
				levelQ.push(*itr);
			}
		}

		cout<<temp<<" ";
	}

	cout<<endl;

}


int main(){

	int nodes = 4;
	std::vector< int > adjList[nodes];

	insertEdge(adjList,0, 1); 
    insertEdge(adjList,0, 2); 
    insertEdge(adjList,1, 2); 
    insertEdge(adjList,2, 0); 
    insertEdge(adjList,2, 3); 
    insertEdge(adjList,3, 3); 
  

  	printBFS(adjList,nodes,1);


}