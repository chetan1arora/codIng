#include <iostream>
#include <vector>
using namespace std;


int minTime(vector<vector<int>> &dp, int arr[], int n, int k, int prev){
    if(k >= n){
        int max_time=arr[0];
        for(int i=1; i<n; ++i){
            if(arr[i] > max_time){
                max_time = arr[i];
            }
        }
        return max_time;
    }
    int new_painter;
    int result;
    if(k > 1 && dp[k-1][n-1] == -1){
        new_painter = max(arr[n-1],minTime(dp,arr,n-1,k-1,arr[n-1])) ;
        dp[k-1][n-1] = new_painter;
    }
    else if(dp[k-1][n-1] == -1){
        int work_sum = arr[0];
        for(int i=1; i< n; ++i){
            work_sum += arr[i];
        }
        new_painter = work_sum;
        dp[k-1][n-1] = new_painter;
    }
    else{
        new_painter = dp[k-1][n-1];
    }
    
    if(prev == 0){
        result = new_painter;
        return result;
    }
    int old_painter = max(arr[n-1]+prev, minTime(dp, arr,n-1,k,arr[n-1]+prev));
    result = min(new_painter,old_painter);
    return result;
}

int main() {
	//code
	int T,n, k;
	int temp;
	cin>>T;
	while(T--){
	    cin>>k;
	    cin>>n;
	    vector< vector< int > > dp(k,vector<int>(n,-1));
	    int arr[n];
	    for(int i=0; i< n; ++i){
	        cin>>arr[i];
	    }
	    cout<<minTime(dp,arr,n,k,0)<<endl;
	}
	
	return 0;
}
