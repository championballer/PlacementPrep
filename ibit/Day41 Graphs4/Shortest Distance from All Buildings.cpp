/*
3 5 1 0 2 0 1 2 0 0 2 0 0 2 1 0 2
3 5 1 0 2 0 1 0 0 0 0 0 0 0 1 0 0
*/

int Solution::solve(vector<vector<int> > &A) {
    
    queue<pair<int,int> > pendingBuildings;
    int total_buildings = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==1)
            {
                pendingBuildings.push(make_pair(i,j));
                total_buildings++;
            }
        }
    }
    
    
    vector<vector<int> > sol(A.size(),vector<int>(A[0].size(),0));
    vector<vector<int> > bvisited(A.size(),vector<int>(A[0].size(),0));
    while(!pendingBuildings.empty())
    {
        pair<int,int> top = pendingBuildings.front();
        pendingBuildings.pop();
        vector<vector<int> > visited(A.size(),vector<int>(A[0].size(),0));
        queue<pair<pair<int,int>,int> > bfs;
        bfs.push(make_pair(top,0));
        
        int flag = 0;
        while(!bfs.empty())
        {
            pair<pair<int,int>,int> stop = bfs.front();
            bfs.pop();
            
            int x = stop.first.first;
            int y = stop.first.second;
            int dis = stop.second;
            if(x<0 || x>=A.size() || y<0 || y>=A[0].size())continue;
            if(visited[x][y]==1)continue;
            visited[x][y] = 1;
            
            if(A[x][y]==1 || A[x][y]==2)
            {
                sol[x][y] = INT_MAX;
                if(flag)continue;
                flag = 1;
            }
            
            else
            {
                if(sol[x][y]==INT_MAX)sol[x][y] = dis;
                else sol[x][y]+=dis;
            }
            bvisited[x][y]++;
            bfs.push(make_pair(make_pair(x+1,y),dis+1));
            bfs.push(make_pair(make_pair(x,y+1),dis+1));
            bfs.push(make_pair(make_pair(x-1,y),dis+1));
            bfs.push(make_pair(make_pair(x,y-1),dis+1));
        }
        
    }
    
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)cout<<sol[i][j]<<" ";
    //     cout<<endl;
    // }
    
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)cout<<bvisited[i][j]<<" ";
    //     cout<<endl;
    // }
    int mn = INT_MAX;
    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol[0].size();j++)
        {
            if(sol[i][j]<mn && bvisited[i][j]==total_buildings)mn = sol[i][j];
        }
    }
    if(mn==INT_MAX)return -1;
    return mn;
    
    return 0;
}
