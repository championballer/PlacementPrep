#include<bits/stdc++.h>

using namespace std;

bool check_sorted(vector<vector<long> >& arr, int x, int y, int n, int m)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i][y]<=arr[i-1][y])return false;
	}

	for(int i=1;i<m;i++)
	{
		if(arr[x][i]<=arr[x][i-1])return false;
	}

	return true;
}

bool check(vector<vector<long> > & arr)
{
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			if(!check_sorted(arr,i,j,arr.size(),arr[0].size()))return false;
		}
	}

	return true;
}


// void swap(int ** arr1, int ** arr2, int i, int j)
// {
// 	int temp = arr1[i][j];
// 	arr1[i][j] = arr2[i][j];
// 	arr2[i][j] = temp;
// }

// bool helper(int ** arr1, int ** arr2,int n,int m)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<m;j++)
// 		{
// 			if(!check(arr1,n,m) || !check(arr2,n,m))
// 			{
// 				swap(arr1,arr2,i,j);
// 				if(check(arr1,n,m) && check(arr2,n,m))return true;
// 				else if(!check_sorted(arr1,i,j,n,m) || !check_sorted(arr2,i,j,n,m))
// 					swap(arr1,arr2,i,j);
// 			}
// 		}
// 	}

// 	return false;
// }

int main()
{
	// int n,m;
	// cin>>n>>m;
	// int ** arr1 = new int*[n];
	// int ** arr2 = new int*[n];

	// for(int i=0;i<n;i++)
	// {
	// 	arr1[i] = new int[m];
	// 	arr2[i] = new int[m];
	// }

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		cin>>arr1[i][j];
	// 	}
	// }

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		cin>>arr2[i][j];
	// 	}
	// }

	// if(helper(arr1,arr2,n,m))
	// {
	// 	cout<<"Possible"<<endl;
	// }

	// else
	// {
	// 	cout<<"Impossible"<<endl;
	// }

	int n,m;
	cin>>n>>m;

	vector<vector<long> > a(n,vector<long>(m,0));
	vector<vector<long> > b(n,vector<long>(m,0));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>b[i][j];
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]>b[i][j])
			{
				swap(a[i][j],b[i][j]);
			}
		}
	}

	cout<<(check(a) && check(b)?"Possible":"Impossible")<<"\n";




}