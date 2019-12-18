int recur_sol(vector<int> &A, int B, int start,vector<int> &path, vector<vector<int>> &sol){
    if(B < 0){
        return -1;
    }
    if(B == 0){
        // Add path to sol
        sol.push_back(vector<int>(path.begin(), path.end()));
        return  -1;
    }
    int temp;
    for(int i=start; i<A.size(); ++i){
        path.push_back(A[i]);
        temp = recur_sol(A, B-A[i], i, path, sol);
        path.pop_back();
        if(temp == -1){
            break;
        }
    }
    return 0;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    vector<int> c;
    int prev;
    if(A.size()){
        c.push_back(A[0]);
        prev = A[0];
    }
    for(int i=1; i<A.size(); ++i){
        if(A[i] == prev){
            continue;
        }
        else{
            c.push_back(A[i]);
            prev = A[i];
        }
    }
    vector<vector<int>> sol;
    vector<int> path;
    
    recur_sol(c, B, 0, path, sol);
    return sol;
}

