#include <iostream>
#include <thread>

using namespace std;

void foo(int a, int b){
	int c = a*b;

	c += b;
	cout<<c<<endl;
	return;
}

/*
* std::threads std
*	c++11
*  pthread
*/

int main(){
	std::thread t1(foo, 5, 4);
	cout<<"Waiting for thread t1"<<endl;
	t1.join();
	cout<<"t1 finishes"<<endl;
}
