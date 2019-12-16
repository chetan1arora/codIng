#include <iostream>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int divide(int A, int B) {
    
    if(A == 0){
        return 0;
    }

    if(B < 0){
        B = (~B)+1;
        cout<<B<<endl;
        A = ( (((A>>31)&1)) << 31) ^ A;
        if(A == 0){
        	A = INT_MAX;
        }
    }
     
    int i=0;
    int b_first;
    for(i=30; i>=0; ++i){
        if((B >> i) & 1){
            b_first = i;
            break;
        }
    }
    int quo = A >> b_first;
    // Check if that is divisible
    b_first++;
    int temp = (1 << b_first) - 1;
    b_first--;
    int lol =   (A & temp) - (B & temp);
    if(lol > 0){
        quo++;
    }
    
    return quo;
}

int main(int argc, char const *argv[])
{
	cout<<divide(-2147483648,-10000000)<<endl;
	return 0;
}