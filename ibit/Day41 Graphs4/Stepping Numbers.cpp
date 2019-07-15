vector<int> Solution::stepnum(int A, int B) {
    
    vector<int> ans;
    queue<int> pendingNodes;
    if(A==0)ans.push_back(0);
    for(int i=1;i<=9;i++)
    {
        pendingNodes.push(i);
    }
    while(!pendingNodes.empty())
    {
        int top = pendingNodes.front();
        if(top>=A)ans.push_back(top);
        pendingNodes.pop();
        int lastDigit = top%10;
        int u = 0;
        int v = 0;
        if(lastDigit!=0)
        {
            u = top*10+lastDigit-1;
            if(u<=B)pendingNodes.push(u);
        }
        if(lastDigit!=9)
        {
            v=top*10+lastDigit+1;
            if(v<=B)pendingNodes.push(v);
        }
        
        
        
    }
    return ans;
}
