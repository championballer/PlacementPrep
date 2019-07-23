#include<bits/stdc++.h>

using namespace std;

void show(vector<int>& arr)
{
	for(int i=0;i<arr.size();i++)
	{
	cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> arr;
	arr.insert(arr.end(),{1,2,3,4,5,6});
	show(arr);
	arr.insert(arr.begin(),{7,8,9,10});
	show(arr);
	sort(arr.begin(),arr.end());
	show(arr);
	
	int index = binary_search(arr.begin(),arr.end(),10);
	cout<<index<<endl;
	
	int index2 = bs
}
