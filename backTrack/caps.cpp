// Blueprint

int wearCap(int start, const vector<vector<int>> &caps, int arr[]){
	if(start == caps.size()){
		return 1;
	}

	long long int count = 0;

	for(int i=0; i<caps[start].size(); ++i){
		if(arr[caps[start][i]] != true){
			arr[caps[start][i]] = true;
			count += wearCap(start+1, caps, myMap);
			arr[caps[start][i]] = false;
		}
	}
	count = count%1000000007;
	return count;
}
