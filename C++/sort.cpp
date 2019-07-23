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
		return b<g.b;
	};
};
int main()
{
	vector<node> a;
	a.push_back(node(4,3));
	a.push_back(node(6,5));
	a.push_back(node(8,1));
	sort(a.begin(),a.end());
	
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].a<<" "<<a[i].b<<endl;
	}

}
