#include <iostream>

using namespace std;


// This is how it should be done // #binarySearch
int binarySearch(int * arr, int l, int r, int key){

	int m;

	while(l <= r){
		// This should always increase
		// Not in case of r-l being 
		m = l + (r-l)/2;

		if(arr[m] == key){
			return m;
		}
		else if(arr[m] > key){
			r = m-1;
		}
		else if(arr[m] < key){
			l = m+1;
		}
	}
	return -1;
}

// Kadane algo

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{	
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<binarySearch(arr, 0, n-1, key)<<endl;

	return 0;

}