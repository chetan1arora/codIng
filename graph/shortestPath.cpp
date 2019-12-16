#include<bits/stdc++.h>

using namespace std;
void buildNode(vector<int> graph[],int start,int n){
    if(start+1 > n){
        return;
    }
    graph[start+1].push_back(start);
    if(3*start > n){
        return;
    }
    graph[3*start].push_back(start);
    return;
}
int travel(vector< int >graph[],int n,vector< int > &minSteps){
    if(minSteps[n] != -1){
        return minSteps[n];
    }
    if(n == 1){
        return 0;
    }
    int temp=n;
    int temp_var;
    for(auto it=graph[n].begin(); it!= graph[n].end(); ++it){
        temp_var = travel(graph,*it,minSteps);
        if(temp_var < temp){
            temp = temp_var;
        }
    }
    minSteps[n] = ++temp;
    return temp;
}
void doThis(int n){
    vector<int> graph[n+1];
    for(int i=1; i<n;++i){
        buildNode(graph,i,n);
    }
    vector<int> minSteps(n+1,-1);
    cout<<"Min steps:"<<endl;
    cout<<travel(graph,n,minSteps)<<endl;
    return;
}

int main() {
	//code
	int T,N;
	cin>>T;
	while(T--){
	    cin>>N;
	    doThis(N);
	}
	return 0;
}