int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==0)return 0;
    if(A<=3)return 1;
    
    int low = 0;
    int high = A;
    int mid = low+(high-low)/2;
    while(low<=high)
    {
        mid = low+(high-low)/2;   
        if((mid==(A/mid)) || (mid<(A/mid) && mid+1>(A/(mid+1))))return mid;
        if(mid>(A/mid))high = mid-1;
        else low = mid+1;
    }
    
    return mid;
}
