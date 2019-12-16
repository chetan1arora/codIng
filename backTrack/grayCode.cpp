void recur_sol(int *seq, int A, vector<int> &sol){
    int temp =1;
    
    
    
    while(A--){
        recur_sol(seq,A,sol);
        if(A == 0){
            sol.push_back(*seq);
        }    // cout<<"lol"<<endl;
        *seq = (*seq)^(temp<<A);
            // cout<<"lol"<<endl;
        if(A == 0){
            sol.push_back(*seq);
        }    
        // cout<<"lol"<<endl;
        // recur_sol(seq,A,sol);
    }
    return;
}
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int *seq,temp=0;
        // cout<<"lol"<<endl;
    seq = &temp;
    // cout<<"lol"<<endl;
    vector<int> sol;
        // cout<<"lol"<<endl;
    recur_sol(seq, A, sol);
    // for(auto itr=sol.begin(); itr != sol.end(); ++itr){
    //     cout<<*itr<<endl;
    // }
    return sol;
}

