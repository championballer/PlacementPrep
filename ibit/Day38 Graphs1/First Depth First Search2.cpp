int Solution::solve(vector<int> &A, const int B, const int C) {
    
    int x = B-1;
    int y = C-1;
    if(x==y)return 1;
    while(x!=0)
    {
        x = A[x]-1;
        if(x==y)return 1;
        
    }
    
    if(x==y)return 1;
    else return 0;
}
