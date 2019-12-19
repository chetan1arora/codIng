#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int minLargestGap(int *arr, int n, int c){

	sort(arr, arr+n);

	int maxWidth = arr[n-1] - arr[0];
	int minWidth = arr[1]-arr[0];
	for(int i=1; i<n ;++i){
		if(arr[i]-arr[i-1] < minWidth){
			minWidth = arr[i]-arr[i-1];
		}
	}

	int temp,minSoFar=INT_MAX,prev,j;
	for(int i=maxWidth; i >= minWidth; --i){
		temp = c-1;
		prev = arr[0];
		for(j=1; j<n; ++j){
			if(arr[j]-prev >= i){
				if(minSoFar > arr[j]-prev){
					minSoFar = arr[j]-prev;
				}
				prev = arr[j];
				temp--;
			}
			if(n-j-1 < temp){
				break;
			}
		}
		if(j == n && temp == 0){
			break;
		}
	}
	return minSoFar;
}

int main(int argc, char const *argv[])
{
	int n,c;
	cin>>n;
	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cin>>c;

	cout<<minLargestGap(arr,n,c)<<endl;

	return 0;
}