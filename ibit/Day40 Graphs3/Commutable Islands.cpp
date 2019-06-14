#include<bits/stdc++.h>

using namespace std;

bool com(vector<int> p1,vector<int> p2)
{
    return p1[2]<p2[2];
}

int findCluster(int c1,vector<int> & parent)
{
    if(parent[c1]==-1)return c1;
    parent[c1] = findCluster(parent[c1],parent);
    return parent[c1];
}

void Union(int c1,int c2,vector<int> & parent,vector<int> & rank)
{
    if(rank[c1]>rank[c2])
    {
        parent[c2] = c1;
    }
    
    else if(rank[c2]>rank[c1])
    {
        parent[c1] = c2;
    }
    
    else
    {
        parent[c1] = c2;
        rank[c1]++;
    }
}

int solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),com);
    // for(int i=0;i<B.size();i++)
    // {
    //     cout<<B[i][0]<<" "<<B[i][1]<<" "<<B[i][2]<<endl;
    // }
    vector<int> rank(A,1);
    vector<int> parent(A,-1);

    //for(int i=0;i<A;i++)parent[i]=i;
    
    int cost = 0;
    for(int i=0;i<B.size();i++)
    {
        
        int n1 = B[i][0]-1;
        int n2 = B[i][1]-1;
        int c = B[i][2];
        
        int c1 = findCluster(n1,parent);
        int c2 = findCluster(n2,parent);
        
        if(c1==c2)continue;
        else
        {
            cost+=c;
            Union(c1,c2,parent,rank);
            
        }
    }
    return cost;
}

int main()
{
    int A;
    cin>>A;

    int edges;
    cin>>edges;

    vector<vector<int> > B(edges,vector<int>(3,0));
    for(int i=0;i<edges;i++)    
    {
        cin>>B[i][0];
        cin>>B[i][1];
        cin>>B[i][2];
    }

    cout<<solve(A,B)<<endl;
}
