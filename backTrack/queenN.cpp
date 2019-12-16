#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

/*
* Shity code since using set
*/
 

void printVector(std::vector< int > &vect){
	vector< int >::iterator itr;
	itr = vect.begin();

	for(;itr != vect.end();++itr){

		cout<<*itr<<" ";
	}
	cout<<endl;

	return;

}


void is_safe(std::vector< int > &loc,int N, std::vector < int > &safe){

	// If only straight moving
	std::set< int > not_safe;

	// As queen can move diagonally
	std::vector< int >::iterator itr;
	std::set < int >::iterator set_itr;
	int dist = loc.size();  
	itr = loc.begin();


	for(;itr != loc.end();++itr){
		not_safe.insert(*itr);
		if(*itr+dist < N){
			not_safe.insert(*itr+dist);
		}
		if(*itr-dist >= 0){
			not_safe.insert(*itr-dist);
		}
		dist--;
	}


	set_itr = not_safe.begin();

	if(not_safe.size() == 0){
		return;
	}

	for(;set_itr != not_safe.end();++set_itr){
		itr = safe.begin();
		for(;itr != safe.end();){
			
			if(*itr == *set_itr)
				safe.erase(itr);
			else
				++itr;
		}
	}

	return;
}

int next_move(vector< int > &loc,int N){

	vector < int > safe_cases;
	int temp = 0;
	while(temp < N){
		safe_cases.push_back(temp++);
	}

	if(loc.size() != 0){
		is_safe(loc,N,safe_cases);
	}

	// Try safe cases with recursion

	while(safe_cases.empty() != true){
		temp = safe_cases.back();
		loc.push_back(temp);

		if(loc.size() == N){
			return 0;
		}	
		if(next_move(loc,N) == 0){
			return 0;
		}
		else{
			loc.pop_back();
		}
		safe_cases.pop_back();
	}

	return -1;
}





int main()
{
	std::vector< int > loc;

	cout<<next_move(loc,8)<<endl;

	cout<<"Location is:"<<endl;
	vector< int >::iterator itr;
	itr = loc.begin();
	int temp=0;

	for(;itr != loc.end();++itr){
		cout<<"("<<*itr<<","<<(temp++)<<"),";
	}
	cout<<endl;

	return 0;
}