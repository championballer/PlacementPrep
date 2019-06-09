#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<set<int> > vect;

	set<int> ourset;
	ourset.insert(5);
	ourset.insert(10);
	ourset.insert(2);

	vect.push_back(ourset);

	
	cout<<*(vect[0].lower_bound(3))<<" ";
	cout<<*(vect[0].upper_bound(3))<<" ";
	cout<<*(vect[0].lower_bound(15)--)<<endl;
}