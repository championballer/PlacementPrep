bool binary_search(vector<int> & A, int B)
{
    int low = 0;
    int high = A.size()-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(A[mid]==B)return 1;
        else if(A[mid]<B)low = mid+1;
        else high = mid-1;
    }
    
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int low = 0;
    int high = A.size()-1;
    
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        
        if(A[mid][0]==B)return 1;
        else if(A[mid][0]<B && A[mid][A[mid].size()-1]>=B)return binary_search(A[mid],B);
        else if(A[mid][0]>B)high = mid-1;
        else low = mid+1;
    }
    
    return 0;
}
