#include<bits/stdc++.h>

using namespace std;

bool bs(vector<int> &A, int B)
{
    int left = 0;
    int right = A.size()-1;
    
    
    
    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(A[mid]==B)return true;
        
        else if(B>A[mid])
        {
            left = mid+1;
        }
        
        else
        {
            right = mid-1;
        }
    }
    
    return false;
}

int main()
{
    vector<int> arr(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    cout<<bs(arr,3)<<endl;
    cout<<bs(arr,8)<<endl;
    cout<<bs(arr,5)<<endl;
}

