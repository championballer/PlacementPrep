vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    
    vector<vector<int> > result;
    
    for(int i=0;i<B.size();i++)
    {
        int current = B[i]%A.size();
        vector<int> current_array;
        
        for(int j=current;j<A.size();j++)current_array.push_back(A[j]);
        for(int j=0;j<current;j++)current_array.push_back(A[j]);
        
        result.push_back(current_array);
        
    }
    
    return result;
}
