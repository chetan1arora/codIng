#include <iostream>
#include <stack>


using namespace std;


int maxProd(int arr[],int n){

	// Left side stack
	stack< pair< int,int > > myStack;
	int left_index[n];

	for(int i=1; i<n; ++i){
		while(myStack.isEmpty() != true){
			if(myStack.top() == arr[i]){
				break;
			}
			myStack.pop();
		}
		if(myStack.isEmpty() == true){
			// Corner case
			left_index[i] = 0;
		}	
		else{
			left_index[i] = myStack.top()->first;
		}
		myStack.push(std::make_pair(arr[i]));
	}
	int max_product = 0;
	// Clear myStack
	int size_temp = myStack.size();
	while(size_temp--){
		myStack.pop();
	}

	int temp;

	for(int j=n-2; j>= 0 ;--j){
		while(myStack.isEmpty() != true){
			if(myStack.top() == arr[i]){
				break;
			}
			myStack.pop();
		}
		if(myStack.isEmpty() != true){
			temp = myStack.top()->first * left_index[i];
			if(temp > max_product){
				max_product = temp;
			}
		}
		myStack.push(std::make_pair(arr[i]));
	}

	return max_product;
}

int main(){
	int temp,n,i=0;
	cin>>n;
	temp = n;
	int arr[n]
	while(temp--){
		cint>>arr[i++];
	}

	cout<<maxProd(arr,n);

	return 0;
}