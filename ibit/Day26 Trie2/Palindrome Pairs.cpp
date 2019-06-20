#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(string A, int s)
{
    int i = s;
    for(int j = A.length()-1;i<=j;i++,j--)
    {
        if(A[i]!=A[j])return false;
    }
    
    return true;
}


class TrieNode{
public:
	char val;
	vector<TrieNode*> children;
	int index;

	TrieNode(char val)
	{
		this->val = val;
		children.assign(26,NULL);
		index = -1;
	}
};

void insR(TrieNode* root, string str, int index)
{
	TrieNode* current = root;
	for(int i=str.length()-1;i>=0;i--)
	{
		
		int x = str[i]-'a';
		
		if(current->children[x]==NULL)
		{
			current->children[x] = new TrieNode(str[i]);
			
		}
		
		if(i==0)
		{
		    current->children[x]->index = index;
		}

		current = current->children[x];
	}
}

void palin(TrieNode* root, int index,vector<int>& result,string & current)
{
	//Reached end of branch
	if(root==NULL)return;

	//Terminal node in branch
	if(root->index!=-1)
	{
		if(root->index!=index)
		{
			string aux = current+root->val;
			if(checkPalindrome(aux,0))
			{

				result.push_back(root->index);
			}	
		}
		
	}

	for(int i=0;i<root->children.size();i++)
	{
		if(root->children[i]!=NULL)
		{
			string aux = current+=root->children[i]->val;
			palin(root->children[i],index,result,current);
		}
	}

	return;


}

void checkStrR(TrieNode* root, string str,int index,vector<vector<int> >& ans)
{
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{

		int x = str[i]-'a';
		/*String being searched reaches end (Lower match)
		    
		    All terminal points ahead, from the node next need to be checked for palindrome
		*/
		
		/*Termination of branch check (Over match)
		    The string left need to be checked for palindrome
	    */
	    
	    /*If both happen at the same time (Clean match)
	    */
	    //cout<<current->val<<endl;
        //cout<<current->index<<endl;
		if(current->children[x]==NULL)
		{
			if(str[i]!=current->val)return;
			//cout<<"Con Entered"<<endl;
		    if(checkPalindrome(str,i))
		    {
		        vector<int> sans;
		     	sans.push_back(index);
		     	sans.push_back(current->index);
		     	ans.push_back(sans);
		    }
		    
		    else return;
		}
		
		else if(i==str.length()-1)
		{

			//cout<<"Con2 Entered"<<endl;
			vector<int> result;
			if(current->children[x]->val!=str[i])return;
// 			cout<<current->index<<endl;
// 			cout<<current->children[x]->index<<endl;
			
			
			string aux = "";
		   	palin(current->children[x],index,result,aux);
		   	for(int j=0;j<result.size();j++)
		   	{
		   		vector<int> sans;
		   		sans.push_back(index);
		   		sans.push_back(result[j]);
		   		ans.push_back(sans);
		   	}

		   	return;
		}
		current = current->children[x];
	}	

	return;	
}


/*
9 tntvmfa lb idsusiuw abcd sjmjfpoh yid dcba m uim
*/

int main()
{

	int n;
	cin>>n;
	vector<string> in;
	for(int i=0;i<n;i++)
	{
		string init;
		cin>>init;
		in.push_back(init);
	}
	TrieNode* root = new TrieNode('\0');
	
	for(int i=0;i<n;i++)
	{
		insR(root,in[i],i);
	}
	vector<vector<int> > ans;
	for(int i=0;i<n;i++)
	{
		checkStrR(root,in[i],i,ans);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
}