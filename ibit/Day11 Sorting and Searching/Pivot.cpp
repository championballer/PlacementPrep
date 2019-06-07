#include<bits/stdc++.h>

using namespace std;

int pivot(vector<int> & A)
{
	int low = 0;
	int high = A.size()-1;

	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(mid+1==A.size() || A[mid+1]<A[mid])return mid;
		else if(A[low]<=A[mid])low = mid+1;
		else high = mid-1;
	}
}

int binary_search(vector<int> & A,int x, int l, int r)
{
	int low = l;
	int high = r;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(A[mid]==x)return mid;
		else if(A[mid]<x)low = mid+1;
		else high = mid-1;
	}

	return -1;
}

int main()
{
	int n;
	cin>>n;

	vector<int> A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	cout<<pivot(A)<<endl;
	cout<<binary_search(A,3,5,9)<<endl;
	cout<<binary_search(A,3,0,4)<<endl;
}