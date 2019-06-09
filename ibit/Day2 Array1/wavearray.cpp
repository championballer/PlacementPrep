vector<int> Solution::wave(vector<int> &A) {
    
    vector<int> result;
    sort(A.begin(),A.end());
    for(int i=0,j=1;i<A.size() || j<A.size();i+=2,j+=2)
    {
        if(j<A.size())
        result.push_back(A[j]);
        
        if(i<A.size())
        result.push_back(A[i]);
    }
    
    return result;
}
