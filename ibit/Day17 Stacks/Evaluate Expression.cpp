int Solution::evalRPN(vector<string> &A) {
    int ans = 0;
    stack<int> st;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/")
        {
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            int ans = 0;
            if(A[i]=="+")ans = f+s;
            else if(A[i]=="-")ans = s-f;
            else if(A[i]=="*")ans = f*s;
            else if(A[i]=="/")ans = s/f;
            
            st.push(ans);
        }
        
        else st.push(stoi(A[i]));
    }
    
    return st.top();
}

