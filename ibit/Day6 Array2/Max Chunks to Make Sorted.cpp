int Solution::solve(vector<int> &A) {
    
    int diff = 0;
    int count = 0;
    for(int i=0;i<A.size();i++)
    {
        diff+=(A[i]-i);
        if(!diff)count++;
    }
    
    return count;
    
}
