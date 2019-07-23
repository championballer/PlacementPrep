int leftIndex(const vector<int> & A, int B)
{
    int low = 0;
    int high = A.size()-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        
        if((mid==0 || B>A[mid-1]) && A[mid]==B)return mid;
        
        else if(B>A[mid])low = mid+1;
        else high = mid-1;
    }
    
    return -1;
}

int rightIndex(const vector<int>& A, int B)
{
    int low = 0;
    int high = A.size()-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if((mid==A.size()-1 || B<A[mid+1]) && A[mid]==B)return mid;
        else if(B<A[mid])high = mid-1;
        else low = mid+1;
    }
    
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result;
    result.push_back(leftIndex(A,B));
    result.push_back(rightIndex(A,B));
    return result;
}

