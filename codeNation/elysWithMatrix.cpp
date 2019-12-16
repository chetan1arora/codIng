#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool sortMyWay(const pair<long int, pair<int,int>> &a,const pair<long int, pair<int,int>> &b ){

	if(a.second.first == b.second.first || a.second.second == b.second.second){
		return a.first < b.first ;
	}
	return true;
}

int main(){
	int M,N;
	cin>>M>>N;
	long int temp;
	vector<pair<long int, pair<int,int>>> data;
	int rank[M][N];
	for(int i=0; i< M; ++i){
		for(int j=0; j<N; ++j){
			rank[i][j] = 1;
			cin>>temp;
			data.push_back(std::make_pair(temp,std::make_pair(i,j)));
		}
	}

	sort(data.begin(), data.end(), sortMyWay);

	int size = data.size();
	// 2 maps i=> value and j=>value
	cout<<"-"<<endl;
	map<int,long int> p_map, q_map;
	vector<vector<pair<long int, pair<int,int>>>> myVecc;
	myVecc.push_back(vector<pair<long int, pair<int,int>>>(0));
	int current_rank =0;
	for(int i=0; i<size; ++i){
		cout<<data[i].first<<" ";
		auto p_itr = p_map.find(data[i].second.first), q_itr = q_map.find(data[i].second.second);
		if(p_itr == p_map.end() && q_itr == q_map.end()){
			p_map.insert({data[i].second.first,data[i].first});
			q_map.insert({data[i].second.second,data[i].first});
		}
		else{
			if(p_itr != p_map.end()){
				if(p_itr->second == data[i].first){
					q_map.insert({data[i].second.second,data[i].first});
				}
				else{
					current_rank++;
					myVecc.push_back(vector<pair<long int, pair<int,int>>>(0));
					map<int,long int> p_map, q_map;
				}
			}
			else if(q_itr != q_map.end()){
				if(q_itr->second == data[i].first){
					p_map.insert({data[i].second.first,data[i].first});
				}
				else{
					current_rank++;
					myVecc.push_back(vector<pair<long int, pair<int,int>>>(0));
					map<int,long int> p_map, q_map;
				}
			}
		}
		// cout<<"LOL"<<endl;
		myVecc[current_rank].push_back(data[i]);
		// cout<<"Nope0"<<endl;
	}
	cout<<endl;


	sort(myVecc[0].begin(),myVecc[0].end());
	for(int j=0; j<myVecc[0].size(); ++j){
		cout<<myVecc[0][j].first<<" ";
			rank[myVecc[0][j].second.first][myVecc[0][j].second.second] = 1; 
	}
	cout<<endl;
	auto it = myVecc[0].end();
	it--;
	long int prev = it->first;
	for(int i=1; i<myVecc.size(); ++i){
		if(myVecc[i].empty()){
			break;
		}
		sort(myVecc[i].begin(),myVecc[i].end());
		for(int j=0; j<myVecc[i].size(); ++j){
			cout<<myVecc[i][j].first<<" ";
			if(myVecc[i][j].first == prev){
				rank[myVecc[i][j].second.first][myVecc[i][j].second.second] = i;	
			}
			else{
				rank[myVecc[i][j].second.first][myVecc[i][j].second.second] = i+1;
			}
		}
		it = myVecc[i].end();
		prev = it->first;
		cout<<endl;
	}

	// pair<int,int> i_rank,j_rank;
	// for(int i=0; i< size; ++i){
	// 	for(int j=0; j< size; ++j){
	// 		if(j == i){
	// 			continue;
	// 		}
	// 		i_rank = data[i].second;
	// 		j_rank = data[j].second;
	// 		if(i_rank.first == j_rank.first || i_rank.second == j_rank.second){
	// 			if(data[i].first > data[j].first && rank[i_rank.first][i_rank.second] <= rank[j_rank.first][j_rank.second]){
	// 				rank[i_rank.first][i_rank.second] = rank[j_rank.first][j_rank.second] + 1;
	// 			}
	// 			else if(data[i].first < data[j].first && rank[i_rank.first][i_rank.second] >= rank[j_rank.first][j_rank.second]){
	// 				rank[j_rank.first][j_rank.second] = rank[i_rank.first][i_rank.second] + 1;
	// 			}
	// 			else if(data[i].first == data[j].first){
	// 				if(rank[i_rank.first][i_rank.second] > rank[j_rank.first][j_rank.second]){
	// 					rank[j_rank.first][j_rank.second] = rank[i_rank.first][i_rank.second];
	// 				}
	// 				else if(rank[i_rank.first][i_rank.second] < rank[j_rank.first][j_rank.second]){
	// 					rank[i_rank.first][i_rank.second] = rank[j_rank.first][j_rank.second];
	// 				} 

	// 			}
	// 		}
	// 	}
	// }

	for(int i=0; i< M; ++i){
		for(int j=0; j<N; ++j){
			cout<<rank[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}


