// bool DFS(vector<int> * neighbours, vector<bool> visited,int n,int source, int destination)
// {
//     //cout<<source<<" "<<destination<<endl;
//     if(source==destination)return true;
//     if(visited[source])return false;
    
//     visited[source] = true;
    
//     for(int i=0;i<neighbours[source].size();i++)
//     {
//         int x = neighbours[source][i];
//         //cout<<x<<endl;
//         bool ans = DFS(neighbours, visited,n,x,destination);
//         if(ans)return ans;
//     }
    
//     return false;
// }

int Solution::solve(vector<int> &A, const int B, const int C) {
    
    vector<int> neighbours[A.size()+1];
    for(int i=0;i<A.size();i++)
    {
        int x = A[i];
        neighbours[x].push_back(i+1);
    }
    
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<neighbours[i].size();j++)
    //     {
    //         cout<<i<<" "<<neighbours[i][j]<<endl;
    //     }
    //     cout<<endl;
    // }
    
    queue<int> pendingNodes;
    vector<bool> visited(A.size(),false);
    pendingNodes.push(C);
    while(!pendingNodes.empty())
    {
        int top = pendingNodes.front();
        pendingNodes.pop();
        if(top==B)return true;
        visited[top] = true;
        
        for(int i=0;i<neighbours[top].size();i++)
        {
            int x = neighbours[top][i];
            if(!visited[x])pendingNodes.push(x);
        }
    }
    
    return false;
}
