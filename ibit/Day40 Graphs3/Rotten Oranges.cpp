int Solution::solve(vector<vector<int> > &A) {
    
    queue<pair<int,int> > parent;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==2)parent.push(make_pair(i,j));
        }
    }
    
    int iter = 0;
    queue<pair<int,int> > children;
    
    int tx[4] = {0,0,-1,1};
    int ty[4] = {-1,1,0,0};
    while(!parent.empty())
    {
        iter++;
        while(!parent.empty())
        {
            pair<int,int> top = parent.front();
            parent.pop();
            
            int x = top.first;
            int y = top.second;
            
            for(int i=0;i<4;i++)
            {
                int x1 = x+tx[i];
                int y1 = y+ty[i];
                if(x1<0 || x1>=A.size() || y<0 || y>=A[0].size())continue;
                if(A[x1][y1]==1)
                {
                    A[x1][y1]=2;
                    children.push(make_pair(x1,y1));
                }
            }
        }
        
        while(!children.empty())
        {
            parent.push(children.front());
            children.pop();
        }
    }
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==1)return -1;
        }
    }
    
    return iter-1;
}
