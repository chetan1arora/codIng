#include <iostream>

using namespace std;

int lowerRange(int arr[],int n, int p){
	int low=0,high=n-1;
	int mid;
	while(low < high){
		mid = (low+high)/2;
		if(arr[mid] >= p){
			high = mid;
		}
		else{
			low = mid;
		}
		if(low+1 == high){
			if(arr[low] == p){
				break;
			}else{
				low = low+1;
			}
		}
	}
	return low;
}

int HigherRange(int arr[],int n, int p){
	int low=0,high=n-1;
	int mid;
	while(low < high){
		mid = (low+high)/2;
		if(arr[mid] <= p){
			low = mid;
		}
		else{
			high = mid;
		}
		if(low+1 == high){
			if(arr[high] == p){
				break;
			}
			else{
				high = high-1;
			}
		}
	}
	return high;
}


int main(){

	int arr[] = {1,1,2,2,2,3,3,3,3,3,5,5,5,9,9,9,13,15,15,16};

	cout<<lowerRange(arr,20,3)+1<<endl;
	cout<<HigherRange(arr,20,5)+1<<endl;
	
	return 0;
}
