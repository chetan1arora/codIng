#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// Make a path of right and down with two numbers

enum direction {right=1, down=0};



int travel(std::vector< pair <int ,int > > &path,int i,int j,const int arr[4][4]){
	// If 0 grey and 1 for possible
	path.push_back(std::make_pair(i,j));

	if(i== 3 && j ==3){
		return 0;
	}

	int success;
	// Right case
	if(arr[i+1][j] == 1 ){
		success = travel(path,i+1,j,arr);
		if(success == 0)
			return 0;
	}
	// down case
	if(arr[i][j+1] == 1 ){
		success = travel(path,i,j+1,arr);
		if(success == 0)
			return 0;
	}

	path.pop_back();

	return -1;
}

int main()
{

	const int arr[4][4] = { { 1, 0, 0, 0 },{ 1, 1, 0, 1 },{ 0, 1, 0, 0 },{ 1, 1, 1, 1 } };

	std::vector< pair < int,int > > path;

	cout<<travel(path,0,0,arr)<<endl;

	std::vector< pair < int,int > >::iterator itr;

	itr = path.begin();

	cout<<"Path is :"<<endl;
	for(;itr != path.end(); ++itr){
		cout<<"("<<itr->first<<","<<itr->second<<"),";
	}
	cout<<endl;

	return 0;
}

