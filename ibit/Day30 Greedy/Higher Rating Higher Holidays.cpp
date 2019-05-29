int Solution::solve(vector<int> &A) {
    vector<int> left(A.size());
    vector<int> right(A.size());
    left[0] = 1;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>A[i-1])left[i] = left[i-1]+1;
        else left[i] = 1;
    }
    right[A.size()-1] = 1;
    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i]>A[i+1])right[i] = right[i+1]+1;
        else right[i] = 1;
    }
    
    int holidays = 0;
    for(int i=0;i<A.size();i++)holidays+=(max(left[i],right[i]));
    
    return holidays;
}
