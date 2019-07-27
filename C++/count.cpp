#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr;
	arr.insert(arr.end(),{1,2,3,4,5,6,7,2,3,1,1,4});
	cout<<count(arr.begin(),arr.end(),1)<<endl;
}