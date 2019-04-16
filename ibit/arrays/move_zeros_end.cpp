vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> nums;
    int zero_count = 0;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=0)nums.push_back(A[i]);
        else zero_count++;
    }
    
    vector<int> result;
    result = nums;
    for(int i=0;i<zero_count;i++)result.push_back(0);
    
    return result;
}
