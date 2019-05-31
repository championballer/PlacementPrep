#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int> > dp(10,vector<int> (11));
	cout<<dp.size()<<" "<<dp[0].size()<<endl;

	for(int i=0;i<dp.size();i++)
	{
		for(int j=0;j<dp[i].size();j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}