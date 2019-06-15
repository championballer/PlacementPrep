int findCluster(int c1, vector<int> & parent)
{
    if(parent[c1]==-1)return c1;
    parent[c1] = findCluster(parent[c1],parent);
    return parent[c1];
}

void Union(int c1,int c2, vector<int> & parent,vector<int> & rank)
{
    if(rank[c1]>rank[c2])parent[c2] = c1;
    else if(rank[c2]>rank[c1])parent[c1] = c2;
    else
    {
        parent[c1] = c2;
        rank[c1]++;
    }
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> rank(A,1);
    vector<int> parent(A,-1);
    vector<int> result;
    for(int i=0;i<B.size();i++)
    {
        int t = B[i][0];
        int n1 = B[i][1]-1;
        int n2 = B[i][2]-1;
        
        if(t==0)
        {
            int c1 = findCluster(n1,parent);
            int c2 = findCluster(n2,parent);
            
            if(c1!=c2)
            {
                Union(c1,c2,parent,rank);
            }
        }
        
        else
        {
            int c1 = findCluster(n1,parent);
            int c2 = findCluster(n2,parent);
            
            if(c1==c2)result.push_back(1);
            else result.push_back(0);
        }
    }
    
    return result;
}
