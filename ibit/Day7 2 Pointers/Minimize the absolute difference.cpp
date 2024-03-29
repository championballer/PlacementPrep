#include<bits/stdc++.h>

using namespace std;

int main()
{
	int s1,s2,s3;
	cin>>s1>>s2>>s3;

	vector<int> A(s1);
	vector<int> B(s2);
	vector<int> C(s3);

	for(int i=0;i<s1;i++)cin>>A[i];
	for(int i=0;i<s2;i++)cin>>B[i];
	for(int i=0;i<s3;i++)cin>>C[i];

	int i = 0, j = 0,k = 0;
    int ans = INT_MAX;
    while(i!=A.size() && j!=B.size() && k!=C.size())
    {
        int mx = max(A[i],max(B[j],C[k]));
        int mn = min(A[i],min(B[j],C[k]));
        
        int diff = abs(mx-mn);
        if(diff<ans)ans = diff;
        
        if(A[i]==mn)
        {
        	if(i!=A.size()-1)i++;
        	else
        	{
        		if(B[j]<=C[k])
        		{
        				if(j!=B.size()-1)j++;
        				else k++;
        		}
        		else if(C[k]<B[j])
        		{
        				if(k!=C.size()-1)k++;
        				else j++;
        		} 
        	}
        }

        else if(B[j]==mn)
        {
        	if(j!=B.size()-1)j++;
        	else
        	{
        		if(A[i]<=C[k])
        		{
        				if(i!=A.size()-1)i++;
        				else k++;
        		}
        		else if(C[k]<A[i])
        		{
        				if(k!=C.size()-1)k++;
        				else i++;
        		} 
        	}
        }

        else if(C[k]==mn)
        {
        	if(k!=C.size()-1)k++;
        	else
        	{
        		if(A[i]<=B[j])
        		{
        				if(i!=A.size()-1)i++;
        				else j++;
        		}
        		else if(B[j]<A[i])
        		{
        				if(j!=B.size()-1)j++;
        				else i++;
        		} 
        	}
        }
    }

    cout<<ans<<endl;
}