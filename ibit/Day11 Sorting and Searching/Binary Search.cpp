#include<bits/stdc++.h>

using namespace std;

int binary_search(vector<int>& A, int x)
{
	int low = 0;
	int high = A.size()-1;

	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(A[mid]==x)return mid;
		else if(A[mid]>x)high=mid-1;
		else low = mid+1;
		
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

	cout<<binary_search(A,5)<<endl;
}