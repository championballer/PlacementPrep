vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> result(A.size(),-1);
    stack<int> st;
    
    for(int i=0;i<A.size();i++)
    {   
        while(!st.empty() && st.top()>=A[i])st.pop();
        
        if(st.empty())result[i]=-1;
        else result[i]=st.top();
        st.push(A[i]);
    }
    
    return result;
}
