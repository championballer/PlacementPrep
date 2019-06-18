vector<int> Solution::solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F, vector<int> &G, vector<int> &H) {
    
    vector<vector<int> > prev(A,vector<int>(A,INT_MAX));
    vector<vector<int> > current(A,vector<int>(A,0));
    
    for(int i=0;i<D.size();i++)
    {
        int f = D[i]-1;
        int s = E[i]-1;
        int w = F[i];
        
        prev[f][s] = min(prev[f][s],w);
        prev[s][f] = min(prev[f][s],w);
    }
    
    for(int i=0;i<prev.size();i++)
    {
        prev[i][i] = 0;
    }
    // for(int i=0;i<prev.size();i++)
    // {
    //     for(int j=0;j<prev[0].size();j++)cout<<prev[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int k=0;k<prev.size();k++)
    {
        for(int i=0;i<prev.size();i++)
        {
            for(int j=0;j<prev.size();j++)
            {
                if(prev[i][k]==INT_MAX || prev[k][j]==INT_MAX)
                {
                    current[i][j] = prev[i][j];
                }
                else current[i][j] = min(prev[i][j],prev[i][k]+prev[k][j]);
            }
        }
        
        prev = current;
    }
    
    
    // for(int i=0;i<current.size();i++)
    // {
    //     for(int j=0;j<current[0].size();j++)cout<<current[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int> result;
    for(int i=0;i<G.size();i++)
    {
        int f = G[i]-1;
        int s = H[i]-1;
        
        int dis = current[f][s];
        if(dis==INT_MAX)result.push_back(-1);
        else result.push_back(dis);
    }
    
    return result;
    
}
