int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    int n = A.size();
    int l = A[0];
    int h = A[n-1];
    
    int ans1 = h-l;
    int limitl = l+B;
    int limitr = h-B;
    if(limitl>limitr)swap(limitl,limitr);
    
    for(int i=1;i<n-1;i++)
    {
        int sub = A[i]-B;
        int add = A[i]+B;
        
        if(sub>=limitl || add<=limitr)continue;
        
        if(limitr-sub<=add-limitl)limitl = sub;
        else limitr = add;
    }
    
    return min(ans1,limitr-limitl);
}
