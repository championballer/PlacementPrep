int Solution::isMatch(const string A, const string B) {
    
    string C = A;
    reverse(C.begin(),C.end());
    string D = B;
    reverse(D.begin(),D.end());
    vector<vector<int> > dp(C.length()+1,vector<int>(D.length()+1,-1));
    dp[0][0]=1;
    
    for(int i=1;i<=D.length();i++)
    {
        if(D[i-1]=='*')dp[0][i] = dp[0][i-1];
        else
        {
            dp[0][i] = 0;
        }
    }
    
    for(int j=1;j<=C.length();j++)
    {
        dp[j][0] = 0;
    }
    
    for(int i=1;i<=C.length();i++)
    {
        for(int j=1;j<=D.length();j++)
        {
            if(D[j-1]!='*' && D[j-1]!='?')
            {
                if(C[i-1]==D[j-1])dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 0;
            }
            
            else if(D[j-1]=='?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            
            else 
            {
                dp[i][j] = dp[i-1][j]||dp[i][j-1];
            }
        }
    }
    
    return dp[A.length()][B.length()];
}
