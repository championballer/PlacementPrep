#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr;
	arr.insert(arr.end(),{4,3,2,1,5,6});
	auto it = max_element(arr.begin(),arr.end());
	cout<<*it<<endl;
	
	cout<<accumulate(arr.begin(),arr.end(),0)<<endl;
}
