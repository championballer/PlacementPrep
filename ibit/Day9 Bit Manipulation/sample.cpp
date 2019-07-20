#include<bits/stdc++.h>

using namespace std;

int main()
{
	bitset<32> alt(20);
	cout<<alt<<endl;
	bitset<32> foo;
	foo.set();
	cout<<foo<<" "<<foo.to_ulong()<<endl;
	
	bitset<32> s1;
	s1 = 43;
	cout<<s1<<endl;
	
	cout<<s1.count()<<endl;
	cout<<s1.size()-s1.count()<<endl;
	
	s1[2] = 1;
	cout<<s1<<endl;
	
	for(int i=s1.size()-1;i>=0;i--)cout<<s1[i];
	cout<<endl;
	
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==1)cout<<s1[i]<<endl;
	}
	
}

