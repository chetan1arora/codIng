#include <iostream>
#include <string>
#include <map>

void min_length(vector<string> &essay, map<string,string> &pocket, long long int *a, long int *b){
	std::map<string,string>::iterator *mapping;
	int count_a,count_b;

	long long int essay_length=0;
	long int num_rs=0;

	for(int i=0; i< essay.size(); ++i){
		mapping = pocket.find(essay[i]);
		detail_maping = pocket_detail.find(essay[i]);
		count_a = detail_maping->first;
		count_b = detail_mapping->second;

		if(count_a > count_b){
			num_rs += count_b;
			essay_length += b.length;
		}
		else if(count_a < count_b){
			num_rs  += count_a;
			essay_length += a.length;
		}

		else{
			if(a.length > b.length){
				num_rs += count_b;
				essay_length += b.length;
			}
			else{
				num_rs += count_a;
				essay_length += a.length;
			}
		}
		// Check for no of r in the

	}

	*a = essay_length;
	*b = num_rs;
	return;
}

int count_rs(const string a){

	for(int i=0; i<a.length; ++i){
		if(a[i] == 'R' || a[i] == 'r'){
			count++;
		}
	}

	return count;
}


int main(){
	vector<string> essay;
	map<string,string> pocket;
	map<string, pair< int,int > > pocket_detail;

	// letter dont matter





}