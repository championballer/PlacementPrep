void DFS(int current, vector<int> n[],vector<bool>& visited, int & v)
{
    if(visited[current])return;
    v++;
    visited[current]=true;
    
    for(int i=0;i<n[current].size();i++)
    {
        int x = n[current][i];
        if(!visited[x])DFS(x,n,visited,v);
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> n[A];
    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            if(B[i][j]==1)n[i].push_back(j);
        }
    }
    
    vector<bool> visited(A,false);
    int ans = 0;
    for(int i=0;i<A;i++)
    {
        int v = 0;
        visited.assign(A,false);
        DFS(i,n,visited,v);
        
        if(v==A)ans++;
    }
    
    return ans;
}
