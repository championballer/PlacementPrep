int Solution::jump(vector<int> &A) {
    
    vector<int> dp(A.size());
    
    dp[A.size()-1] = 0;
    
    for(int i=A.size()-2;i>=0;i--)
    {
        int mn = INT_MAX;
        for(int j=1;j<=A[i];j++)
        {
            if(i+j>=A.size())continue;
            if(dp[i+j]==-1)continue;
            if(dp[i+j]<mn)mn = dp[i+j];
        }
        
        if(mn==INT_MAX)
        {
            dp[i] = -1;
        }
        else dp[i] = mn+1;
    }
    
    return dp[0];
}
