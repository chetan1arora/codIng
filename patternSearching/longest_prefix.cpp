#include <iostream>
#include <map>
#include <string>

using namespace std;

int longestPrefix(string &a){
	int len = a.size();
	map<int,int> cases;
	map<int, int>::iterator itr;

	for(int i=1; i<len; ++i){
		if(cases.size()){
			for(itr=cases.begin(); itr!= cases.end();++itr){
				if(a[i] == a[itr->second]){
					itr->second++;
				}else{
					cases.erase(itr->first);
				}
			}
		}
		if(a[i] == a[0]){
			cases.insert(pair<int, int>(len-i,1));
		}
	}
	int max_len = 0;
	for(itr=cases.begin();itr!= cases.end(); ++itr){
		if(itr->first > max_len){
			max_len = itr->first;
		}
	}

	return max_len;
}


int main(){
	int T;
	cin>>T;
	string a;
	while(T--){
		cin>>a;
		cout<<longestPrefix(a)<<endl;
	}

}
