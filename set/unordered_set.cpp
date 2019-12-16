#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;


char findMissing(const string &a,const string &b){


	std::unordered_set < char > setA;

	std::string::const_iterator itr = a.begin();
	for(;itr != a.end();++itr){
		setA.insert(*itr);
	}

	itr = b.begin();
	for(;itr != b.end();++itr){
		if(setA.find(*itr) == setA.end()){
			return *itr;
		}
	}
	return '\0';
}

int main(int argc, char const *argv[])
{
	const string a = "abcd";
	const string b = "cbdea";

	cout<<findMissing(a,b)<<endl;

	return 0;
}