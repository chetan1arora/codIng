#include <iostream>
#include <iterator>
#include <queue>

using namespace std;

int main(){
	int arr[7] = {7,1,5,9,6,4,3};

	std::priority_queue< int > prQ;

	for(int i=0;i<7;++i){
		prQ.push(arr[i]);
	}

	cout<<"Priority queue :"<<endl;
	while(prQ.empty() != true){
		cout<<prQ.top()<<" ";
		prQ.pop();
	}
	cout<<endl;
	return 0;
}