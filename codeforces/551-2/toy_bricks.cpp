#include<bits/stdc++.h>

using namespace std;

int main()
{
	int l,w,h;

	cin>>l>>w>>h;

	vector<int> front;
	vector<int> left;

	for(int i=0;i<w;i++)
	{
		int current;
		cin>>current;
		front.push_back(current);
	}

	for(int i=0;i<l;i++)
	{
		int current;
		cin>>current;

		left.push_back(current);
	}

	int ** top = new int*[l];
	for(int i=0;i<l;i++)
	{
		top[i] = new int[w];
		for(int j=0;j<w;j++)
		{
			top[i][j] = 0;
		}
	}

	for(int i=0;i<l;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>top[i][j];
		}
	}

	for(int i=0;i<l;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(top[i][j]!=0)
			{
				top[i][j]=min(left[i],front[j]);
			}
			
		}
	}

	for(int i=0;i<l;i++)
	{
		for(int j=0;j<w;j++)
		{
			cout<<top[i][j]<<" ";
		}

		cout<<endl;
	}


}