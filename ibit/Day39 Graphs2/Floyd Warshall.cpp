vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    vector<vector<int> > prev(A.size(),vector<int>(A[0].size(),0));
    vector<vector<int> > current(A.size(),vector<int>(A[0].size(),0));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==-1)prev[i][j]=INT_MAX;
            else prev[i][j] = A[i][j];
        }
    }
    
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)cout<<prev[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    for(int k=0;k<A.size();k++)
    {
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
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
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(current[i][j]==INT_MAX)current[i][j]=-1;
        }
        
    }
    
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)cout<<current[i][j]<<" ";
    //     cout<<endl;
    // }
    return current;
}
