#include<bits/stdc++.h>

using namespace std;

struct node{
	int index;
	bool op;
	int value;
}

node* construct_tree(vector<int> & parent)
{
	int i=2;

	for(int j=0;j<parent.size();j++)
	{
		
	}
}

int main()
{
	int n;
	vector<int> op_nodes;
	for(int i=0;i<n;i++)
	{
		int current;
		cin>>current;
		op_nodes.push_back(current);
	}

	vector<int> parent;
	for(int i=0;i<n-1;i++)
	{
		int current;
		cin>>current;

		parent.push_back(current);
	}

	node* root = construct_tree(parent);
}