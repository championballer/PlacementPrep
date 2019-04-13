#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;

	vector<pair<int,int> > input;

	for(int i=0;i<n;i++)
	{
		int s,d;
		cin>>s>>d;

		input.push_back(make_pair(s,d));
	}

	int ans = 0;
	int flag = 1;
	while(true)
	{
		for(int i=0;i<n;i++)
		{
			if(input[i].first==t)
			{
				ans= i;
				flag = 1;
				break;
			}

			else
			{
				input[i].first+=input[i].second;
			}

			//cout<<input[i].first<<" ";
		}

		if(flag==1)break;
	}

	cout<<ans+1<<endl;
}