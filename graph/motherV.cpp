#include <iostream>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

void insertEdge(list< int > *adjList, int a, int b){
	adjList[a].push_back(b); // ONly directed graph
	return;
}

void dfsR(vector< bool > &visited, int vertex,std::list< int > *adjList){

	visited[vertex] = true;

	std::list< int >::iterator itr = adjList[vertex].begin();

	for(;itr != adjList[vertex].end();++itr){
		if(visited[*itr] == false){
			dfsR(visited,*itr,adjList);
		}
	}

	return;

}


int findMother(list< int > * adjList,int V){

	std::vector< bool > visited(V,false);
	int i=0;
	int last;
	for(;i<V;++i){
		if(visited[i] == false){
			dfsR(visited,i,adjList);
			last = i;
		}
	}

	// last is only one who can be mother vertex


	std::vector< bool >::iterator itr = visited.begin();
	for(;itr != visited.end();++itr){
		*itr = false;
	}

	dfsR(visited,last,adjList);
	// If all are visited
	itr = visited.begin();

	for(;itr != visited.end();++itr){
		if(*itr == false){
			return -1;
		}
	}

	return last;

}

int main()
{	
	int Nodes = 7;
	list< int > adjList[7];
    insertEdge(adjList,0, 1); 
    insertEdge(adjList,0, 2); 
    insertEdge(adjList,1, 3); 
    insertEdge(adjList,4, 1); 
    insertEdge(adjList,6, 4); 
    insertEdge(adjList,5, 6); 
    insertEdge(adjList,5, 2); 
    insertEdge(adjList,6, 0);

    cout<<"Mother Vortex e if found = "<< findMother(adjList,Nodes)<<endl;


	return 0;
}