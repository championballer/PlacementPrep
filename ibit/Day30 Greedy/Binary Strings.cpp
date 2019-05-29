int Solution::solve(string A, int B) {
    
    vector<int> s(A.length());
    int count = 0;
    for(int i=0;i<A.size()-B+1;i++)
    {
        if((A[i]+s[i])%2==0)
        {
            count++;
            for(int j=i;j<i+B;j++)
            {
                s[j]++;
            }
        }
    }
    
    for(int i=A.size()-B;i<A.size();i++)
    {
        if((A[i]+s[i])%2==0)return -1;
    }
    
    return count;
    
}
