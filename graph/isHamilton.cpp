#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[],int a, int b){

	graph[a].push_back(b);
	graph[b].push_back(a);
	return;
}

bool goDeep(vector<int> graph[],int V, int start, bool visited[], int *dist){

	*dist = *dist +1;
	if(*dist == V){
		// Path reached
		return true;
	}
	visited[start] = true;
	for(auto it=graph[start].begin(); it != graph[start].end(); ++it){
		if(visited[*it] == false){
			if(goDeep(graph,V, *it, visited, dist) == true){
				return true;
			}
		}
	}
	visited[start] = false;
	*dist = *dist-1;
	return false;
}

int isHamiltonian(vector<int> graph[],int V){

	int *dist;

	*dist = 0;
	bool visited[V];
	for(int i=0; i<V; ++i){
		visited[i] = false;
	}

	for(int j=0; j< V; ++j){
		if(goDeep(graph,V,j,visited,dist) == true){
			return 1;
		}
	}
	return 0;
}

int main(){
	int T,V,M;
	cin>>T;
	int a,b;
	while(T--){
		cin>>V;
		vector<int> graph[V];
		cin>>M;
		for(int i=0; i<M; ++i){
			cin>>a;
			cin>>b;
			a--;
			b--;
			addEdge(graph,a,b);
		}
		cout<<isHamiltonian(graph,V)<<endl;
	}
	return 0;
}