#include<bits/stdc++.h>

using namespace std;

int main()
{
	unordered_map<int,set<int> > ourmap;

	set<int> ourset;
	ourset.insert(1);
	ourset.insert(2);

	ourmap[1] = ourset;

	for(auto it = ourmap.begin();it!=ourmap.end();it++)
	{
		for(set<int>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<*it2<<" ";
		}
		cout<<endl;
	}
}