int Solution::solve(vector<int> &A) {

    sort(A.begin(),A.end());
    
    int mn = INT_MAX;
    
    for(int i=1;i<A.size();i++)
    {
        int current_diff = A[i]-A[i-1];
        
        if(current_diff<mn)mn = current_diff;
    }
    
    return mn;
    
}
