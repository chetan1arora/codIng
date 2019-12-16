#include <iostream>
#include <vector>

using namespace std;


long int maxHappiness(vector<int> &p,long int arr[],bool visited[],int N,long long int xor_left){
	long int min=0;
	int min_idx =0;
	int lost =1;
	for(int i=0; i<N; ++i){
		if(visited[i] == false){
			if( < max){
				max = xor_left^arr[i];
				max_idx = i;
			}
			lost = 1;
		}
	}
	if(lost == 1){
		return 0;
	}

	visited[max_idx] = true; 
	xor_left = max;
	p.push_back(max_idx);

	return max + maxHappiness(p, arr, visited, N, xor_left);
}



int main(){
	int T, N;
	cin>>T;
	int i=0;
	long int xor_left=0;
	while(T--){
		cin>>N;
		long int arr[N];
		i=0
		while(N--){
			cin>>arr[i++];
			xor_left = xor_left^arr[i-1];
		}
		vector<int> path;
		cout<<maxHappiness(path,)
	}
}