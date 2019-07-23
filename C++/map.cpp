#include<bits/stdc++.h>

using namespace std;

class node{

	public:
	int a;
	int b;
	
	node(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	
	bool operator <(const node&g)const{
		return b>g.b;
	};
};

int main()
{
	map<node,bool> ourmap;
	ourmap[node(1,3)] = 1;
	ourmap[node(3,2)] = 1;
	ourmap[node(0,5)] = 1;
	
	for(auto it = ourmap.begin();it!=ourmap.end();it++)
	{
		cout<<it->first.a<<" "<<it->first.b<<" "<<it->second<<endl;
	}
}
