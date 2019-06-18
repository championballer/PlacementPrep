int Solution::solve(vector<vector<int> > &A) {
    
    vector<vector<int> > prev(A.size(),vector<int>(A[0].size(),-1));
    vector<vector<int> > current(A.size(),vector<int>(A[0].size(),0));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(i==j)prev[i][j] = 0;
            else if(A[i][j]==-1)prev[i][j]=INT_MAX;
            else prev[i][j] = A[i][j];
        }
    }
    
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
    
    vector<int> mx;
    for(int i=0;i<A.size();i++)
    {
        int m = INT_MIN;
        for(int j=0;j<A[0].size();j++)
        {
            m = max(m,current[i][j]);
        }
        mx.push_back(m);
        //cout<<mx[i]<<" ";
    }
    //cout<<endl;
    
    
    int result = 0;
    int val = INT_MAX;
    for(int i=0;i<mx.size();i++)
    {
        if(val>mx[i])
        {
            val = mx[i];
            result = i;
        }
    }
    
    return result;
    
}