vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int> > result;
    
    for(int i=0;i<A;i++)
    {
        if(i==0)
        {
            vector<int> init;
            init.push_back(1);
            result.push_back(init);
        }
        
        else
        {
            vector<int> current;
            for(int j=0;j<=i;j++)
            {
                if(j==0)current.push_back(1);
                else if(j==i)current.push_back(1);
                
                else
                {
                    current.push_back(result[i-1][j-1]+result[i-1][j]);
                }
            }
            
            result.push_back(current);
        }
    }
    
    return result;
}
