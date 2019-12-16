#include <iostream>
#include <vector>

using namespace std;

int maximize( const std::vector< int > &values,const std::vector< int > &weights ,int len ,int maxW){
	int temp = weights[len-1];
	if(len == 1){
		if(temp <= maxW ){
			return values[0]; // Including case
		}
		else{
			return 0; // Excluding case
		}

	}
	else{
		if(temp < maxW)
			return max(values[len-1] + maximize(values,weights,len-1,maxW-temp), maximize(values,weights,len-1,maxW)); // One excluding case and one including case
		else if(temp == maxW)
			return max(values[len-1],maximize(values,weights,len-1,maxW));
		else
			return maximize(values,weights,len-1,maxW);
	}

}


int main()
{	
	std::vector< int > values ;
	values.push_back(120);
	values.push_back(100);
	values.push_back(60);
	std::vector< int > weights;
	weights.push_back(30);
	weights.push_back(20);
	weights.push_back(10);

	int maxW;
	maxW = 50;


	if(values.size() != weights.size()){
		cout<<"Values of both are not given"<<endl;
		return 0;
	}
	cout<<"Maximum maximum value: "<<endl;

	cout<<maximize(values,weights,values.size(),maxW)<<endl;
	
	return 0;
}