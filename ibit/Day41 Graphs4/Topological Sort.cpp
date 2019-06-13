int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<int> neighbours[A];
    vector<int> incoming(A,0);
    for(int i=0;i<B.size();i++)
    {
        int x = B[i]-1;
        int y = C[i]-1;
        neighbours[x].push_back(y);
        incoming[y]++;
    }
    
    queue<int> q;
    for(int i=0;i<incoming.size();i++)
    {
        if(incoming[i]==0)q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(int i=0;i<neighbours[top].size();i++)
        {
            int n = neighbours[top][i];
            incoming[n]--;
            if(incoming[n]==0)q.push(n);
        }
    }
    
    if(ans.size()==A)return 1;
    else return 0;
}
