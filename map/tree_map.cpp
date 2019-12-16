#include <iostream>
#include <map>
#include <iterator>

using namespace std;


int main(int argc, char const *argv[])
{
	map <int,int> treemap;


	treemap.insert(pair<int,int>(-1,35));
	treemap.insert(pair<int,int>(-1,20));
	treemap.insert(pair<int,int>(2,50));
	treemap.insert(pair<int,int>(1,90));
	treemap.insert(pair<int,int>(-3,40));
		

	map<int,int>::iterator itr,it;

	itr = treemap.begin();
	cout<<"ldfs"<<itr->first<<endl;
	for(;itr != treemap.end();++itr){
		cout<<itr->first<<": "<<itr->second<<endl;
	}

	itr = treemap.find(4);
	if(itr == treemap.end())
		cout<<":" << itr->first <<  "   " << itr->second <<endl;

	it = treemap.find(4);
	if(it == treemap.end()){
		cout<<"lol"<<endl;
	}

  	return 0;
}
