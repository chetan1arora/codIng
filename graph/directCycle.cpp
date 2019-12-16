#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        int v, e;
        cin >> v >> e;
        
        vector<int> adj[v];
        
        for(int i =0;i<e;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        cout << isCyclic(v, adj) << endl;
        
    }
    
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool travel(vector<int> adj[],int start,bool visited[],int V){
    if(visited[start] == true){
        return true;
    }
    visited[start] = true;
    for(auto it=adj[start].begin(); it!= adj[start].end(); ++it){
        if(travel(adj,*it,visited,V) == true){
            return true;
        }
    }
    visited[start] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V] = {false};
    for(int i=0; i<V; ++i){
        if(travel(adj,i,visited,V) == true){
            return true;
        }
    }
    return false;
}