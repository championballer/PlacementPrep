#include<bits/stdc++.h>

using namespace std;

int minimumSwaps(vector<int> & arr) {

    int ans = 0;
    for(int i=0;i<arr.size()-1;)
    {
        //cout<<"index:"<<i<<endl;
        if(arr[i]==i+1)
        {
            i++;
        }
        else 
        {
            //cout<<"arr[i] "<<arr[i]<<endl;
            int temp = arr[i];
            //cout<<"arr[arr[i]-1] "<<arr[arr[i]-1]<<endl;
            arr[i] = arr[arr[i]-1];
            arr[temp-1] = temp;
            ans++;
        }
    }

    return ans;
}

int main()
{

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<minimumSwaps(arr)<<endl;
}