string Solution::longestPalindrome(string A) {
    
    vector<vector<bool> > dp(A.length(),vector<bool>(A.length(),0));
    
    for(int i=0,j=0;i<A.length();i++,j++)dp[i][j] = 1;
    
    for(int c=1;c<A.length();c++)
    {
        for(int i=0,j=c;j<A.length();i++,j++)
        {
            if(A[i]==A[j])
            {
                if(i+1>j-1)dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1];
            }
            else dp[i][j] = 0;
        }
    }
    
    int l=0,r=0;
    int mx = 0;
    for(int i=0;i<A.length();i++)
    {
        for(int j=0;j<A.length();j++)
        {
            if(dp[i][j])
            {
                if(j-i>mx)
                {
                    mx = j-i;
                    l = i;
                    r = j;
                }
            }
        }
    }
    
    string ans = "";
    ans = A.substr(l,r-l+1);
    
    return ans;
    
}
