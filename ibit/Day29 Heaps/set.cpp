#include<bits/stdc++.h>

using namespace std;

class node{

	public:
	int a;
	int b;
	
	node(int a, int b)
	{
	   this->a = a;
	   this->b = b;
	}
	
	bool operator < (const node& g) const{
		return b>g.b;
	}
};

int main()
{
	set<node> s;
	s.insert(node(2,3));
	s.insert(node(3,4));
	
	for(auto it  = s.begin();it!=s.end();it++)
	{
		cout<<it->a<<" "<<it->b<<endl;
	}
	
	s.erase(s.find(node(2,3)));
	
}
