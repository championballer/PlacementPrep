/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    
    ll * a = new ll[n];
    ll * b = new ll[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    
    ll * s1 = new ll[n+1];
    s1[0] = 0;
    ll * s2 = new ll[n+1];
    s2[0] = 0;
    
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            s1[i] = s1[i-1]+b[i-1];
            s2[i] = s2[i-1]+a[i-1];
        }
        
        else
        {
            s1[i] = s1[i-1]+a[i-1];
            s2[i] = s2[i-1]+b[i-1];
        }
    }
    
    for(int i=0;i<=n;i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=n;i++)
    {
        cout<<s2[i]<<" ";
    }
    cout<<endl;
    
    // for(int i=0;i<q;i++)
    // {
    //     int t,f,s;
    //     cin>>t>>f>>s;
    //     if(t==1)
    //     {
    //         cout<<s1[s]-s1[f-1]<<endl;
    //     }

    //     else
    //     {
    //         cout<<s2[s]-s2[f-1]<<endl;
    //     }
    // }    
}
