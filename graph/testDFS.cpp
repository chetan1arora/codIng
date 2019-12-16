#include <iostream>
#include <list>
#include <stack>
using namespace std;



void travel(list< int > graph[],int start,bool visited[]){
	if(visited[start] == true){
		return;
	}
	visited[start] = true;
	cout<<start<<" ";
	int temp = *(++graph[start].begin());
	travel(graph,temp,visited);
	return;
}

void printDFS(list< int > graph[],int V,bool visited[]){
	
	stack< int > depth;
	travel(graph,2,visited);
	for(int i=0; i< V; i++){
		travel(graph,i,visited);
	}
	cout<<endl;
	return;
}

int main(int argc, char const *argv[])
{
	int V = 4;
	list< int > graph[V];
 	
	bool visited[V] = {false};


	graph[0].push_back(1);
	graph[0].push_back(2);

	graph[1].push_back(2);
	// graph[1].push_back(4);
	// graph[1].push_back(2);
	// graph[1].push_back(3);
	
	graph[2].push_back(0);
	graph[2].push_back(3);

	graph[3].push_back(3);
	// graph[3].push_back(4);
	// graph[3].push_back(2);

	// graph[4].push_back(3);
	// graph[4].push_back(0);
	// graph[4].push_back(1);



	printDFS(graph,V,visited);

	return 0;
} 