#include<bits/stdc++.h>

using namespace std;

int calculate_area(const vector<int> &A, int x, int y)
{
	int val = min(A[x],A[y]);
	int result = 0;
	for(int i=x+1;i<y;i++)
	{
		result+=(val-A[i]);
	}

	return result;
}

/*
10 0 2 1 0 4 6 3 1 4 5
*/
int trap(const vector<int> &A) {

	int total_area = 0;
	vector<int> left_scan(A.size(),0);
	vector<int> right_scan(A.size(),0);

	int mx = A[0];
	left_scan[0] = 0;
	for(int i=1;i<A.size();i++)
	{	
		left_scan[i] = mx;
		if(A[i]>mx)mx = A[i];
	}

	right_scan[A.size()-1] = 0;
	mx = A[A.size()-1];
	for(int i=A.size()-2;i>=0;i--)
	{
		right_scan[i] = mx;
		if(A[i]>mx)mx = A[i];
	}

	// for(int i=0;i<A.size();i++)cout<<left_scan[i]<<" ";
	// 	cout<<endl;
	// for(int i=0;i<A.size();i++)cout<<right_scan[i]<<" ";
	// 	cout<<endl;

	for(int i=0;i<A.size();i++)
	{
		int candidate = min(left_scan[i],right_scan[i])-A[i];
		if(candidate>0)total_area+=candidate;
	}
	return total_area;
}

int main()
{
	int n;
	cin>>n;

	vector<int> in(n);
	for(int i=0;i<n;i++)cin>>in[i];

	cout<<trap(in)<<endl;
}
