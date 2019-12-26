#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &A) {
    
    if(A.empty()){
        return 0;
    }
    stack<pair<int,int>> s;
    s.push(std::make_pair(0,-1));
    // if(A.back() != 0){
    //     A.push_back(0);
    // }
    int maxSoFar = A[0];
    // int cIdx;
    int temp,top_stack;
    for(int i=1; i<A.size(); ++i){
        // cIdx = i;
        while(!s.empty() && s.top().first > A[i]){
        	top_stack = s.top().first;
        	s.pop();
            temp = top_stack*(i-s.top().second-1);
            // cout<<"lol"<<endl;
            if(temp > maxSoFar){
                maxSoFar = temp;
            }
            
        }
        if(s.top().first < A[i]){
            s.push(std::make_pair(A[i],i));
        }
    }
    while(!s.empty() && s.top().first > 0){
            temp = s.top().first*(A.size()-s.top().second);
            if(temp > maxSoFar){
                maxSoFar = temp;
            }
            s.pop();
    }
    
    return maxSoFar;
}

int main(int argc, char const *argv[])
{
	int arr[] = { 90, 58, 69, 70, 82, 100, 13, 57, 47, 18 } ;

	std::vector<int> v;

	for(int i=0; i<10; ++i){
		v.push_back(arr[i]);
	}

	cout<<largestRectangleArea(v)<<endl;

	return 0;
}
