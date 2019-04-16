int max(vector<int> & A)
{
    int mx = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>mx)mx = A[i];
    }
    
    return mx;
}

int min(vector<int> & A)
{
    int mn = INT_MAX;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<mn)mn = A[i];
    }
    
    return mn;
}
int Solution::maxArr(vector<int> &A) {
    
    vector<int> arr1;
    vector<int> arr2;
    
    for(int i=0;i<A.size();i++)
    {
        arr1.push_back(A[i]+i);
        arr2.push_back(A[i]-i);
    }
    
    int sub1 = max(arr1)-min(arr1);
    int sub2 = max(arr2)-min(arr2);
    
    return max(sub1,sub2);
    
    
}
