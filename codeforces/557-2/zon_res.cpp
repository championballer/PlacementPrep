#include<bits/stdc++.h>

using namespace std;

void print_array(int * arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void set_value(int * arr, int size,int value)
{
	for(int i=0;i<size;i++)
	{
		arr[i] = value;
	}
}

int main()
{
	int n,h,m;
	cin>>n>>h>>m;

	int * max_height = new int[n];
	set_value(max_height,n,h);

	for(int i=0;i<m;i++)
	{
		int f,s,r;
		cin>>f>>s>>r;

		for(int j=f-1;j<s;j++)
		{
			max_height[j] = min(r,max_height[j]);
			print_array(max_height,n);
		}
	}

	long long cost = 0;

	for(int i=0;i<n;i++)
	{
		cost+=(max_height[i]*max_height[i]);
	}

	cout<<int(cost)<<endl;
}