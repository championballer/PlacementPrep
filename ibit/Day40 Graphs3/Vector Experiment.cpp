#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int> > B;

	vector<int> v1{1,2,3};
	vector<int> v2{3,1,2};
	vector<int> v3{1,3,2};
	B.push_back(v1);
	B.push_back(v2);
	B.push_back(v3);

	sort(B.begin(),B.end());

	for(int i=0;i<B.size();i++)
	{
		for(int j=0;j<B[i].size();j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
}