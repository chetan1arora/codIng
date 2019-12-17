#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void foo(int a, int b){
	int c = a*b;
	c += b;
	cout<<"this thread is going to sleep for 1 min"<<endl;
	std::this_thread::sleep_for(std::chrono::minutes(1));
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
