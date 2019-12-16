#include <iostream>
#include <vector> 
using namespace std;

int maximize( const std::vector< int > &values,const std::vector< int > &weights ,int len ,int maxW, std::vector< std::vector< int > > &dp){
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
		if(temp < maxW){

			if(dp[maxW][len-1] == -1)
				dp[maxW][len-1] = maximize(values,weights,len-1,maxW,dp);

			if(dp[maxW-temp][len-1] == -1)
				dp[maxW-temp][len-1] = maximize(values,weights,len-1,maxW-temp,dp);

			return max(values[len-1] + dp[maxW-temp][len-1] , dp[maxW][len-1] ); // One excluding case and one including case
		}
		else if(temp == maxW){
			if(dp[maxW][len-1] == -1)
				dp[maxW][len-1] = maximize(values,weights,len-1,maxW,dp);
			return max(values[len-1],dp[maxW][len-1]);
		}
		else{
			if(dp[maxW][len-1] == -1)
				dp[maxW][len-1] = maximize(values,weights,len-1,maxW,dp);

			return dp[maxW][len-1];
		}
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


	std::vector< std::vector<int > > dp(maxW+1,vector< int > (values.size(),-1));

	cout<<"Maximum maximum value: "<<endl;

	cout<<maximize(values,weights,values.size(),maxW,dp)<<endl;
	
	return 0;
}