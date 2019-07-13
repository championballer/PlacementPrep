int solve(vector<int> & A, int i, int * dp)
{
    if(i>=A.size())return 0;
    if(dp[i]!=-1)return dp[i];
    
    int mn = INT_MAX;
    for(int j=A[i];j>0;j--)
    {
        int sans = solve(A,i+j,dp);
        if(sans==INT_MAX)continue;
        else sans++;
        if(sans<mn)mn = sans;
    }
    dp[i] = mn;
    return mn;
}

int Solution::jump(vector<int> &A) {
    int * dp = new int[A.size()];
    memset(dp,-1,sizeof(int)*A.size());
    dp[A.size()-1] = 0;
    
    int ans =  solve(A,0,dp);
    if(ans==INT_MAX)return -1;
    else return ans;
}
