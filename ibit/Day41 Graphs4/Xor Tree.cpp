

void helper(int current, vector<int>n[],vector<int> & dp, vector<bool> & visited)
{
    //cout<<current<<endl;
    if(visited[current])return;
    visited[current] = true;
    if(n[current].size()==0)
    {
        return;
    }
    int ans = dp[current];
    for(int i=0;i<n[current].size();i++)
    {
        int x = n[current][i];
        //cout<<x<<endl;
        if(!visited[x])
        {
            helper(x,n,dp,visited);
            ans^=dp[x];
        }
        //if(!visited[x])ans^=dp[x];
    }
    //visited[current] = false;
    dp[current] = ans;
    
}


vector<int> Solution::solve(int A, vector<int> &B, vector<vector<int> > &C) {
    
    vector<int> n[A];
    for(int i=0;i<C.size();i++)
    {
        int x = C[i][0];
        int y = C[i][1];
        
        n[x].push_back(y);
        n[y].push_back(x);
    }
    
    vector<int> dp(A,0);
    dp = B;
    vector<bool> visited(A,false);
    helper(0,n,dp,visited);
    int mx = INT_MIN;
    int f = 0;
    for(int i=0;i<dp.size();i++)mx = max(dp[i],mx);
    for(int i=0;i<dp.size();i++)
    {
        if(dp[i]==mx)f++;
    }
    vector<int> result(2,0);
    result[0] = mx;
    result[1] = f;
    return result;
}
