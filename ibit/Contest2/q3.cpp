int findParent(int c,vector<int>& parent)
{
    if(parent[c]==-1)return c;
    parent[c] = findParent(parent[c],parent);
    return parent[c];
}

void Union(int c1, int c2, vector<int>& parent,vector<int>& rank)
{
    if(rank[c1]>rank[c2])
    {
        parent[c2] = c1;
        rank[c1]+=rank[c2];
    }
    
    else
    {
        parent[c1] = c2;
        rank[c2]+=rank[c1];
    }
}

int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    
    vector<int> parent(A,-1);
    vector<int> rank(A,0);
    for(int i=0;i<A;i++)rank[i] = B[i];
    
    for(int i=0;i<C.size();i++)
    {
        int x = C[i][0]-1;
        int y = C[i][1]-1;
        int c1 = findParent(x,parent);
        int c2 = findParent(y,parent);
        if(c1!=c2)
        {
            Union(c1,c2,parent,rank);
        }
    }
    
    int ans = 0;
    for(int i=0;i<parent.size();i++)
    {
        if(parent[i]==-1 && rank[i]>=D)ans++;
    }
    return ans;
}
