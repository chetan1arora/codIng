#include <bits/stdc++.h>
using namespace std;

void next_palin(string &s){
	bool change_flag=false;
	long int i=0,j=s.size()-1;

	while(i < j){
		if(s[i] > s[j]){
			s[j] = s[i];
			change_flag = true;
		}
		else if(s[i] < s[j]) {
			s[j] = s[i];
			change_flag = false;
		}
		i++;
		j--;
	}
	if(i != j){
		i--;
		j++;
	}
	if(i == j && !change_flag){
		if(s[i] != '9'){
			s[i] = ++s[i];
			change_flag =true;
		}
		else{
			s[i] = '0';
			i--;
			j++;
		}
	}

	while(i != j && !change_flag && i >= 0){
		if(s[i] != '9'){
			s[i]++;
			s[j]++;
			change_flag = true;
		}
		else{
			s[i--] = '0';
			s[j++] = '0';
		}
	}
	if(!change_flag){
		s.push_back('1');
		s[0] = '1';
		for(int k=1; k< s.size()-1; ++k){
			s[k] = '0';
		}
	}
	return;

}

int main() {
	int T;
	long int i;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		i=0;
		while(s[i++] == '0'){
		}
		if(i-1 < s.size()){
			s.erase(0,i-1);
			next_palin(s);
			cout<<s<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
		
	return 0;
}

