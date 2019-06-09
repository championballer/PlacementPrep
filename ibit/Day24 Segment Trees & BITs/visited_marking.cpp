#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	cin>>a;

	int * A = new int[a];
	for(int i=0;i<a;i++)
	{
		cin>>A[i];
	}

	int n;
	cin>>n;

	int * B = new int[n];
	int * C = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>B[i];
		cin>>C[i];
	}

	int * level = new int[a];
	bool * visited = new bool[a];
	memset(visited,false,sizeof(bool)*a);
	bool * completed = new bool[n];
	memset(completed,false, sizeof(bool)*n);

	int complete = 0;
	int i = 0;

	level[0] = 0;
	visited[0] = true;

	while(complete<n)
	{
		int b = B[i]-1;
		int c = C[i]-1;

		if(!completed[i]&& (visited[b] || visited[c]))
		{
			if(visited[b])
			{
				level[c] = level[b]+1;
				visited[c] = true;
			}

			else
			{
				level[b] = level[c]+1;
				visited[b] = true;
			}
			completed[i] = true;
			complete++;
		}

		else i = (i+1)%n;
		
	}

	int mx = INT_MIN;
	for(int i=0;i<a;i++)
	{
		if(level[a]>mx)mx = level[a];
	}
	
	for(int i=0;i<a;i++)cout<<level[i]<<" ";
	cout<<endl;

	unordered_map<int, set<int> > ourmap;

	for(int i=0;i<a;i++)
	{
		int l = level[i];

		if(ourmap.count(l))
		{
			ourmap[l].insert(A[i]);
		}

		else
		{
			set<int> ourset;
			ourset.insert(A[i]);
			ourmap[l] = ourset;
		}
	}


	for(auto it = ourmap.begin();it!=ourmap.end();it++)
	{
		cout<<it->first<<" ";
		for(auto it2=it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<*it2<<" ";
		}
		cout<<endl;
	}

	int q;
	cin>>q;

	int * lquery = new int[q];
	int * vquery = new int[q];
	for(int i=0;i<q;i++)cin>>lquery[i];
	for(int i=0;i<q;i++)cin>>vquery[i];

	for(int i=0;i<q;i++)
	{
		cout<<*((ourmap[lquery[i]%mx+1].upper_bound(vquery[i])))<<endl;
	}




}