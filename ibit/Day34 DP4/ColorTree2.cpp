#include<bits/stdc++.h>

using namespace std;

int k = 0;
int dp[100000][3];

class TreeNodeAux{
public:
	int val;
	TreeNodeAux* left;
	TreeNodeAux* right;
	TreeNodeAux(int x):val(x),left(NULL),right(NULL){}	
};

int mxgreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(dp[root->val][color]!=-1)return dp[root->val][color];

	if(color==0)
	{
		dp[root->val][color] = mxgreen(root->left,1)+mxgreen(root->right,2)+1;
		return dp[root->val][color];
	}

	else if(color==1)
	{
		dp[root->val][color] = max((mxgreen(root->left,0)+mxgreen(root->right,2)),(mxgreen(root->left,2)+mxgreen(root->right,0)));
		return dp[root->val][color];
	}

	else
	{
		dp[root->val][color] = max((mxgreen(root->left,0)+mxgreen(root->right,1)),(mxgreen(root->left,1)+mxgreen(root->right,0)));
		return dp[root->val][color];	
	}
}

int mngreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(dp[root->val][color]!=-1)return dp[root->val][color];

	if(color==0)
	{
		dp[root->val][color] = mngreen(root->left,1)+mngreen(root->right,2)+1;
		return dp[root->val][color];
	}

	else if(color==1)
	{
		dp[root->val][color] = min((mngreen(root->left,0)+mngreen(root->right,2)),(mngreen(root->left,2)+mngreen(root->right,0)));
		return dp[root->val][color];
	}

	else
	{
		dp[root->val][color] = min((mngreen(root->left,0)+mngreen(root->right,1)),(mngreen(root->left,1)+mngreen(root->right,0)));
		return dp[root->val][color];	
	}	
}

TreeNodeAux* makeTree(string s)
{
	TreeNodeAux* root = new TreeNodeAux(k);
	TreeNodeAux* current = root;
	k++;
	stack<TreeNodeAux*> st;
	int index = 0;
	while(index!=s.length())
	{
		if(s[index]=='0')
		{
			if(!st.empty())
			{
				current = st.top();
				st.pop();	
			}
			index++;
		}

		else if(s[index]=='1')
		{
			current->left = new TreeNodeAux(k);
			k++;
			current = current->left;
			index++;
		}

		else if(s[index]=='2')
		{
			current->left = new TreeNodeAux(k);
			k++;
			current->right = new TreeNodeAux(k);
			k++;
			st.push(current->right);
			current=current->left;
			index++;
		}
	}

	return root;
}

int main()
{
	string s;
	cin>>s;
	TreeNodeAux* root = makeTree(s);
	//printTree(root);
	memset(dp,-1,sizeof(int)*100000*3);
	cout<<mxgreen(root,0)<<endl;
	memset(dp,-1,sizeof(int)*100000*3);
	cout<<mngreen(root,1)<<endl;
}