vector<int> Solution::solve(vector<int> &A) {
    
    
    stack<int> zpos;
    stack<int> neg;
    
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]>=0)
        {
            zpos.push(A[i]);
            A.pop_back();
        }
        
        else
        {
            neg.push(A[i]);
            A.pop_back();
        }
    }

    while(!zpos.empty() && !neg.empty())
    {
        A.push_back(neg.top());
        neg.pop();
        A.push_back(zpos.top());
        zpos.pop();
    }
    
    while(!zpos.empty())
    {
        A.push_back(zpos.top());
        zpos.pop();
    }
    
    while(!neg.empty())
    {
        A.push_back(neg.top());
        neg.pop();
    }
    
    return result;
}
