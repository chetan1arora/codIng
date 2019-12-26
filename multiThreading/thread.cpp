#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m;

void foo(int *a){
	m.lock();
	*a = *a +1;
	m.unlock();
	return;
}

/*
* std::threads std
*	c++11
*  pthread
*/

int main(){
	int zero = 0;
	std::vector<std::thread> arr;
	for(int i=0; i<1000; ++i){
		arr.push_back(std::thread(foo,&zero));
	}
	for(auto t=arr.begin(); t != arr.end(); ++t){
		(*t).join();
	}
	cout<<zero<<endl;
	return 0;
}
