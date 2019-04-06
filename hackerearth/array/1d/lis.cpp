#include<bits/stdc++.h>

using namespace std;

int lis(vector<int> arr)
{
	vector<int> result;
	result.push_back(1);
	int max = 1;
	for(int i=1;i<arr.size();i++)
	{
		int candidate = 1;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i]>arr[j])
			{
				if(result[j]>=candidate)
				{
					candidate = result[j]+1;
				}
			}
		}

		result.push_back(candidate);
		if(candidate>max)max = candidate;
	}

	return max;

}

int main()
{
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int current;
		cin>>current;

		arr.push_back(current);
	}

	cout<<lis(arr)<<endl;
}