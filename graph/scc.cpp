#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <stack>
using namespace std;

void insertEdge(list< int > *adjList, int a, int b){
	adjList[a].push_back(b); // ONly directed graph
	return;
}

void dfsR(vector< bool > &visited, int vertex,std::list< int > *adjList, std::stack< int > &strong){

	visited[vertex] = true;

	std::list< int >::iterator itr = adjList[vertex].begin();

	for(;itr != adjList[vertex].end();++itr){
		if(visited[*itr] == false){
			dfsR(visited,*itr,adjList,strong);
		}
	}
	strong.push(vertex);

	return;

}

void dfsR_without_stack(vector< bool > &visited, int vertex,std::list< int > *adjList){

	visited[vertex] = true;

	cout<<vertex<<" ";

	std::list< int >::iterator itr = adjList[vertex].begin();

	for(;itr != adjList[vertex].end();++itr){
		if(visited[*itr] == false){
			dfsR_without_stack(visited,*itr,adjList);
		}
	}
	return;

}


void revGraph(std::list< int > *adjList,std::list< int > *revAdjList,int V){

	// V is the number of nodes in the graph
	int i=0;

	std::list< int >::iterator itr;

	for(;i<V;++i){
		itr = adjList[i].begin();

		for(;itr != adjList[i].end();++itr){
			revAdjList[*itr].push_back(i);
		}
	}


	// Reversed Source and Sink of Graph
	return;



}


int printSCC(list< int > * adjList,int V){

	std::stack< int > strong;

	std::vector< bool > visited(V,false);
	int i=0;

	for(;i<V;++i){
		if(visited[i] == false){
			dfsR(visited,i,adjList,strong);
		}
	}

	// strong has most strongest connected areas elements 

	// Switch Source and Sink Points in Graph
	list< int > revAdjList[V];

	revGraph(adjList,revAdjList,V);

	std::vector< bool >::iterator itr = visited.begin();
	for(;itr != visited.end();++itr){
		*itr = false;
	}

	int temp;
	while(strong.empty() != true){
		temp = strong.top();
		if(visited[temp] == false){
			dfsR_without_stack(visited,temp,revAdjList);
			cout <<endl;
		}
		strong.pop();
	}




}

int main()
{	
	int Nodes = 5;
	list< int > adjList[5];
    insertEdge(adjList, 1, 0); 
    insertEdge(adjList, 0, 2); 
    insertEdge(adjList, 2, 1); 
    insertEdge(adjList, 0, 3); 
    insertEdge(adjList, 3, 4); 
  
    printSCC(adjList,5);

	return 0;
}