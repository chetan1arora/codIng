#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(int* arr,int i);

void swap(int *a,int *b);
void makeHeap(int *arr,int size){
	int i;
	for(i=(size/2)-1;i >= 0;--i){
		heapify(arr, i);
	}

	cout<<"Priority Queue elements are:"<<endl;
	for(i=0;i<size;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

void heapify(int* arr, int i){

	// i is the parent of 2*i+1 and 2*i +2
	bool swapped = false;
	if(arr[i] < arr[2*i+2]){
		swap(arr+i,arr+2*i +2);
		swapped = true;
	}

	if(arr[i] < arr[2*i+1]){
		swap(arr+i,arr+2*i +1);
		swapped = true;
	}

	if(swapped == true && i!= 0){
		heapify(arr,(i-1)/2);
	}
	return;
}


void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
	return;
}

int main(int argc, char const *argv[])
{
	int arr[7] = {7,1,5,9,6,4,3};
	makeHeap(arr,7);

	cout<<"Log of :"<<log2(343)<<endl;

	cout<<"power "<<pow(2,floor(log2(343)))<<endl;
	return 0;
}