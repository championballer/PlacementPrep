#include<bits/stdc++.h>

using namespace std;

int main()
{
	unordered_map<int,int> ourmap;
	ourmap[0] = 1;
	ourmap[1] = 2;

	for(auto it = ourmap.begin();it!=ourmap.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}