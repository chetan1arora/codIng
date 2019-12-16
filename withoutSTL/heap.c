#include <stdio.h>
#include <stdlib.h>

/*
* Making a heap using C
* Writing heap methods
* No class 
* Max heap
*/

// One path heapify O(n) for a heap
void heapify(int * arr, int n, int r){
	if(r >= n){
		return arr;
	}
	int temp;
	if(2*r+1 < n && arr[2*r+1] > arr[r]){
		temp = arr[2*r+1];
		arr[2*r+1] = arr[r];
		arr[r] = temp;
		heapify(arr,n, 2*r+1);
	}
	if(2*r+2 < n && arr[2*r+2] > arr[r]){
		temp = arr[2*r+2];
		arr[2*r+2] = arr[r];
		arr[r] = temp;
		heapify(arr,n, 2*r+2);
	}
	return;
}
// First time heap
void makeHeap(int * arr, int n){
	for(int i=n/2; i >=0 ; --i){
		heapify(arr, n, i);
	}
	
}

int main(int argc, char const *argv[])
{


	return 0;
}
