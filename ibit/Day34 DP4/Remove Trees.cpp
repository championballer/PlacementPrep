#include<bits/stdc++.h>

using namespace std;

int dp[19][19];

int helper(vector<int> & A, int x, int y)
{
	
	if(dp[x][y]!=-1)return dp[x][y];
	if(y-x<2)return 0;
	if(y-x==2)
	{
		dp[x][y] = A[x]*A[x+1]*A[x+2];
		return dp[x][y];
	}
	int mn = INT_MAX;
	for(int i = x+1;i<y;i++)
	{
		mn = min((A[x]*A[i]*A[y]+helper(A,x,i)+helper(A,i,y)),mn);
	}
	return mn;
}

int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)cin>>A[i];
	memset(dp,-1,sizeof(dp));
	cout<<helper(A,0,n-1)<<endl;
}