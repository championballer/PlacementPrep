#include<bits/stdc++.h>

using namespace std;

int k = 1;

class TreeNodeAux {
public:
	int val;
	TreeNodeAux* left;
	TreeNodeAux* right;
	TreeNodeAux(int x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};

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
	printTree(root);
}