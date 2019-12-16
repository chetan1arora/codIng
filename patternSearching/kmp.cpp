#include <iostream>
#include <map>
#include <string>
#include <vector>

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

void search(string &txt, string &pat, vector<int> &lps){
	int i=0,j=0;
	while(i< txt.size()){
		if(txt[i] == pat[j]){
			i++;
			j++;
			if(j == pat.size()){
				cout<<"Match found at "<<i-j<<endl;
			}
		}
		else{
			if(j > 0){
				//no change in i;
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
}


int main(){

	string pat,temp,txt;
	cin>>txt;
	cin>>pat;

	vector< int > lps;
	lps.push_back(0);
	if(pat[0] == pat[1]){
		lps.push_back(1);
	}
	else{
		lps.push_back(0);
	}

	for(int j=2; j<pat.size(); ++j){
		temp = pat.substr(0,j+1);
		lps.push_back(longestPrefix(temp));
	}

	// Printing
	for(auto it=lps.begin(); it != lps.end(); ++it){
		cout<<*it<<endl;
	}

	// now pattern searching

	search(txt,pat,lps);

	return 0;

}
