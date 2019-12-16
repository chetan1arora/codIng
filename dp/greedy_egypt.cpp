#include <iostream>


using namespace std;
void printEgypt(int nr,int dr){

	if(dr%nr == 0){
		cout << "1/"<<dr/nr;
		return;
	}

	if(nr%dr == 0){
		cout<<nr/dr;
	}

	if(nr > dr){
		cout<<nr/dr;
		printEgypt(nr%dr,dr);
	}

	int n = dr/nr + 1;

	cout<<"1/"<<n;
	printEgypt(nr*n-dr,n*dr);

}

