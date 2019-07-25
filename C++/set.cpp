#include<bits/stdc++.h>

using namespace std;

int main()
{
	set<int> s;
	s.insert(2);
	int myints[] = {3,4,5,6};
	s.insert(myints,myints+4);

	auto it = s.find(3);
	auto it2 = s.find(2);
	cout<<distance(s.begin(),it)<<endl;
	cout<<distance(s.begin(),it)<<endl;
}