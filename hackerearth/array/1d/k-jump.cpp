#include<bits/stdc++.h>

using namespace std;

int kjump(vector<int> A, int K)
{
   int result = 0;
   
   for(int i=0;i<A.size();i++)
   {
       set<int> ourset; 
       
       int target = A[i];
       for(int j=i+1;j<A.size();j++)
       {
           int current = A[j];
           if(current-target>=K)
           {
               ourset.insert(target);
               ourset.insert(current);
               target = current;
           }
       }
       
       if(ourset.size()>result)result = ourset.size();
   }
   
   return result;
}

int main()
{
	int k;
	cin>>k;
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		int current;
		cin>>current;
		arr.push_back(current);
	}

	cout<<kjump(arr,k)<<endl;
}