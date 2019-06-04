#include<bits/stdc++.h>

using namespace std;

int current = 1;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	vector<int> mx;
	vector<int> mn;
	TreeNode(int x):val(x),left(NULL),right(NULL),mx(3,-1),mn(3,-1){}	
};




void printTree(TreeNode* root)
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

void makeTree(string s, int index,TreeNode* root,stack<TreeNode*> & st)
{
	if(index==s.length())return;
	if(s[index]=='0')
	{	
		if(!st.empty())
		{
			TreeNode* top = st.top();
			st.pop();	
			makeTree(s,index+1,top,st);
		}
		else return;
		
			
	}
	if(s[index]=='1')
	{
		root->left = new TreeNode(current);
		current++;
		makeTree(s,index+1,root->left,st);
	}

	if(s[index]=='2')
	{
		root->left = new TreeNode(current);
		current++;
		root->right = new TreeNode(current);
		current++;

		st.push(root->right);
		makeTree(s,index+1,root->left,st);
	}	
}


int main()
{
	string s;
	cin>>s;
	stack<TreeNode*> st;
	int value = 0;
	TreeNode* root = new TreeNode(current);
	current++;
	makeTree(s,0,root,st);
	printTree(root);
}