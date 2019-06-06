int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    
    int result = 0;
    for(int i=0,j=A.size()-1;i<j;)
    {
        int current = A[i]+A[j];
        if(current==B)
        {
            result++;
            i++;
            j--;
        }
        
        else if(current<B)
        {
            i++;
        }
        
        else j--;
    }
    
    return result;
    
}
