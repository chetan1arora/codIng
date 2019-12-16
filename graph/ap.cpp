#include <iostream>
#include <vector>


using namespace std;

void addEdge(vector< int > * arr,int a, int b){
	arr[a].push_back(b);
	arr[b].push_back(a);
	return;
}


void dfsUtil(vector<int> graph[],int V,int root,bool visited[],int parent[],int link[],vector<int> &ap){
	visited[root] = true;

	int num_childs = 0;
	link[root] = -1;
	if(graph[root].size() == 1){
		link[root] = parent[root];
	}
	for(auto it=graph[root].begin(); it!= graph[root].end(); ++it){
		if(visited[*it] == false){
			parent[*it] = root;
			num_childs++;
			dfsUtil(graph,V,*it,visited,parent,link,ap);

			//Checking and adding to AP
			
			if(parent[root] == -1 && num_childs ==2){ // Dont want to push it again and again
				ap.push_back(root);
			}

			if(parent[root]!= -1 && link[*it] == root){
				// That means ki root is removable
				ap.push_back(root);
				link[*it] = parent[root];
			}

			// Change the dist of root
			link[root] = link[*it];
		}	
		else if(parent[root] != *it){
			link[root] = *it;
		}
	}

	return;
	
}

void dfs(vector<int> graph[],int V){
	// Assuming connected
	// Assuming undirected
	bool visited[V];
	int parent[V];
	int link[V];
	vector<int> ap;
	for(int j=0;j<V; ++j){
		visited[j] = false;
		parent[j] = -1;
		link[j] = -1; // Put it
	}
	dfsUtil(graph,V,0,visited,parent,link,ap);
	cout<<"distance:"<<endl;
	for(int k=0; k< V; k++){
		cout<<link[k]<<" ";
	}
	cout<<endl;

	for(auto it=ap.begin(); it!= ap.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
	return;

}



int main(){

	int nodes = 5;
	std::vector< int > g1[nodes];  
    addEdge(g1, 1, 0); 
    addEdge(g1, 0, 2); 
    addEdge(g1, 2, 1); 
    addEdge(g1, 0, 3); 
    addEdge(g1, 3, 4);
    
    dfs(g1,nodes);

    // g1.AP(); 
  
    // cout << "\nArticulation points in second graph \n"; 
    // Graph g2(4); 
    // addEdge(g2, 0, 1); 
    // addEdge(g2, 1, 2); 
    // addEdge(g2, 2, 3); 
    // // g2.AP();
    // dfs(g2,nodes);
  
    // cout << "\nArticulation points in third graph \n"; 
    // Graph g3(7); 
    // addEdge(g3 ,0, 1); 
    // addEdge(g3,1, 2); 
    // addEdge(g3,2, 0); 
    // addEdge(g3,1, 3); 
    // addEdge(g3,1, 4); 
    // addEdge(g3,1, 6); 
    // addEdge(g3,3, 5); 
    // addEdge(g3,4, 5); 
    // // g3.AP();
    // dfs(g3,nodes);
    return 0;

}