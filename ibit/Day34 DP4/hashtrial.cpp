#include<bits/stdc++.h>

using namespace std;

int current = 1;
class TreeNodeAux{
public:
	int val;
	TreeNodeAux* left;
	TreeNodeAux* right;
	vector<int> mx;
	vector<int> mn;
	TreeNodeAux(int x):val(x),left(NULL),right(NULL),mx(3,-1),mn(3,-1){}	
};


int mxgreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(root->mx[color]!=-1)return root->mx[color];

	if(color==0)
	{
		root->mx[color] = mxgreen(root->left,1)+mxgreen(root->right,2)+1;
		return root->mx[color];
	}

	else if(color==1)
	{
		root->mx[color] = max((mxgreen(root->left,0)+mxgreen(root->right,2)),(mxgreen(root->left,2)+mxgreen(root->right,0)));
		return root->mx[color];
	}

	else
	{
		root->mx[color] = max((mxgreen(root->left,0)+mxgreen(root->right,1)),(mxgreen(root->left,1)+mxgreen(root->right,0)));
		return root->mx[color];	
	}
}

int mngreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(root->mn[color]!=-1)return root->mn[color];

	if(color==0)
	{
		root->mn[color] = mngreen(root->left,1)+mngreen(root->right,2)+1;
		return root->mn[color];
	}

	else if(color==1)
	{
		root->mn[color] = min((mngreen(root->left,0)+mngreen(root->right,2)),(mngreen(root->left,2)+mngreen(root->right,0)));
		return root->mn[color];
	}

	else
	{
		root->mn[color] = min((mngreen(root->left,0)+mngreen(root->right,1)),(mngreen(root->left,1)+mngreen(root->right,0)));
		return root->mn[color];	
	}	
}

void printTree(TreeNodeAux* root)
{
	if(root==NULL)return;

	else
	{
		cout<<root->val<<":";
		if(root->left)cout<<"L:"<<root->left->val;
		if(root->right)cout<<"R:"<<root->right->val;
		cout<<endl;
		if(root->left)printTree(root->left);
		if(root->right)printTree(root->right);
	}
}

void makeTree(string s, int index,TreeNodeAux* root,stack<TreeNodeAux*> & st)
{
	if(index==s.length())return;
	if(s[index]=='0')
	{	
		if(!st.empty())
		{
			TreeNodeAux* top = st.top();
			st.pop();	
			makeTree(s,index+1,top,st);
		}
		else return;
		
			
	}
	if(s[index]=='1')
	{
		root->left = new TreeNodeAux(current);
		current++;
		makeTree(s,index+1,root->left,st);
	}

	if(s[index]=='2')
	{
		root->left = new TreeNodeAux(current);
		current++;
		root->right = new TreeNodeAux(current);
		current++;

		st.push(root->right);
		makeTree(s,index+1,root->left,st);
	}	
}


int main()
{
	string s;
	cin>>s;
	stack<TreeNodeAux*> st;
	int value = 0;
	TreeNodeAux* root = new TreeNodeAux(current);
	current++;
	makeTree(s,0,root,st);
	//printTree(root);
	cout<<mxgreen(root,0)<<endl;
	cout<<mngreen(root,1)<<endl;
}