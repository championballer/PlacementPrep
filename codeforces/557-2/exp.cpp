#include<bits/stdc++.h>

using namespace std;

void take_input(vector<vector<long> > & arr)
{
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			cin>>arr[i][j];
		}
	}
}

void print_matrix(vector<vector<long> > & arr)
{
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<long> > a(n,vector<long>(m,0));
	vector<vector<long> > b(n,vector<long>(m,0));
	take_input(a);
	take_input(b);

}