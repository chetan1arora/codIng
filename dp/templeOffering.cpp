#include <iostream>
using namespace std;

void print_sol(int arr[], int n){
    
	vector<pair<int,int>> extremes;
	vector<int> sol(n);

	extremes.push_back(std::make_pair(arr[0],0));

	for(int i=1; i<n-1; ++i){
		if(arr[i] <= arr[i-1] && arr[i] <= arr[i+1])
			extremes.push_back(std::make_pair(arr[i],i));
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
			extremes.push_back(std::make_pair(arr[i],i));

	}
	extremes.push_back(std::make_pair(arr[n-1],n-1));

	int numPairs = extremes.size();
	int count =1;
	for(int i=0; i<numPairs-1; ++i){
		count =1;
		if(extremes[i].first < extremes[i+1].first){
			for(int j=extremes[i].second; j <= extremes[i+1]; ++j){
				sol[j] = count++;
			}
		}
		else if(extremes[i].first > extremes[i+1].first){
			for(int j=extremes[i+1].second; j >= extremes[i].second; --j){
				sol[j] = count++;
			}
		}
	}
	return sol;
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
        for(int i=0; i<n; ++i){
            cin>>arr[i];
        }
        print_sol(arr, n);
	}

	return 0;
}