int findParent(int c, vector<int> & parent)
{
    if(parent[c]==-1)return c;
    parent[c] = findParent(parent[c],parent);
    return parent[c];
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
        parent[c2] = c1;
        
        rank[c1]++;
    }
}

//7 2 0 3 2 8 1 6 5 1 9 1 1 4 0 4
int Solution::solve(vector<vector<int> > &A) {
    
    unordered_map<int,pair<int,int> > mapping;
    int n = INT_MIN;
    int m = INT_MIN;
    unordered_map<int,vector<int> > rows;
    unordered_map<int,vector<int> > cols;
    for(int i=0;i<A.size();i++)
    {
        int x = A[i][0];
        int y = A[i][1];
        if(rows.count(x))
        {
            rows[x].push_back(i);
        }
        
        else
        {
            vector<int> temp;
            temp.push_back(i);
            rows[x] = temp;
        }
        
        if(cols.count(y))
        {
            cols[y].push_back(i);
        }
        
        else
        {
            vector<int> temp;
            temp.push_back(i);
            cols[y]=temp;
        }
        n = max(n,x);
        m = max(m,y);
        mapping[i] = make_pair(x,y);
    }
    
    vector<int> parent(A.size(),-1);
    vector<int> rank(A.size(),1);
    //cout<<"First"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<rows[i].size();j++)
        {
            int f = rows[i][j-1];
            int s = rows[i][j];
            //cout<<f<<" "<<s<<endl;
            int c1 = findParent(f,parent);
            int c2 = findParent(s,parent);
            if(c1!=c2)
            {
                Union(c1,c2,parent,rank);
            }
        }
    }
    //cout<<"Second"<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=1;j<cols[i].size();j++)
        {
            int f = cols[i][j-1];
            int s = cols[i][j];
            //cout<<f<<" "<<s<<endl;
            int c1 = findParent(f,parent);
            int c2 = findParent(s,parent);
            if(c1!=c2)
            {
                Union(c1,c2,parent,rank);
                
            }
        }
    }
    
    
    int ans = 0;
    unordered_map<int,bool> moves;
    for(int i=0;i<parent.size();i++)
    {
        int p = findParent(i,parent);
        //cout<<parent[i]<<" ";
        if(parent[i]==-1)moves[i] = 1;
        else ans++;
    }
    //cout<<endl;
    
    
    return ans;
    
    
}
