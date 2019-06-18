#include<bits/stdc++.h>

using namespace std;

int main()
{
	int A = 4;
	int B = 5;
	vector<vector<vector<int> > > dp(4,vector<vector<int> > (A,vector<int>(B,0)));
	for(int i=0;i<dp.size();i++)
	{
		for(int j=0;j<dp[0].size();j++)
		{
			for(int k=0;k<dp[0][0].size();k++)
			{
				cout<<dp[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	
}