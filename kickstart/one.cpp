#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main()
{
    ll t;
    cin>>t;
    
    for(int k=1;k<=t;k++)
    {
        ll n,p;
        cin>>n>>p;
        
        ll * skills = new ll[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>skills[i];
        }
        
        sort(skills,skills+n);
        
        ll training_required_main = INT_MAX;
        for(int i=0;i<n-p+1;i++)
        {
            ll threshold = skills[i+p-1];
            ll training_required = 0;
            for(int j=i;j<i+p;j++)
            {   
                training_required += (threshold-skills[j]);
            }
            if(training_required<training_required_main)
            {
                training_required_main = training_required;
            }
        }
        
        cout<<"Case #"<<k<<": "<<training_required_main<<endl;
    }
}