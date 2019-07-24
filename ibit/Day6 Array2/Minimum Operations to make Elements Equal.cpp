int Solution::solve(vector<vector<int> > &A, int B) {
    
    vector<int> arr;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            arr.push_back(A[i][j]);
        }
    }
    
    sort(arr.begin(),arr.end());
    int mn = arr[0];
    int med = -1;
    if(arr.size()%2==0)
    {
        int f = arr.size()/2;
        int s = (arr.size()+1)/2;
        
        med = (arr[f]+arr[s])/2;
    }
    
    else
    {
        med = arr[(arr.size()+1)/2];
    }
    
    int steps = 0;
    for(int i=0;i<arr.size();i++)
    {
        if((arr[i]-mn+B)%B!=0)return -1;
        else steps+=(abs(med-arr[i])/B);
    }
    
    return steps;
    
}
