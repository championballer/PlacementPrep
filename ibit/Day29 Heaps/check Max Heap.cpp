bool checkMaxHeap(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    
    for(int i=0;i<n;i++)
    {
        int f = 2*i+1;
        int s = 2*i+2;
        
        if(f<n)
        {
            if(arr[i]<arr[f])return false;
        }
        
        if(s<n)
        {
            if(arr[i]<arr[s])return false;
        }
    }
    
    return true;
}

