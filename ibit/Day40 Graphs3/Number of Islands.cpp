void dfs(vector<vector<int> > & state, int x, int y)
{
    if(x<0 || x>=state.size() || y<0 || y>=state[0].size())return;
    if(state[x][y]==0 || state[x][y]==2)return;
    
    state[x][y] = 2;
    int tx[8] = {1,0,1,-1,-1,-1,0,1};
	int ty[8] = {0,1,1,1,0,-1,-1,-1};
    
    for(int i=0;i<8;i++)
    {
        dfs(state,x+tx[i],y+ty[i]);
    }
    
}

int Solution::solve(vector<vector<int> > &A) {
    
    int calls = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==0 || A[i][j]==2)continue;
            else
            {
                dfs(A,i,j);
                calls++;
            }
        }
    }
    
    return calls;
}
