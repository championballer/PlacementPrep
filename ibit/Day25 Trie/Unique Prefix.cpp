#include<bits/stdc++.h>

using namespace std;

class TrieNode{
public:
	char val;
	int occur;
	bool term;
	vector<TrieNode* > children;

	TrieNode(char val)
	{
		this->val = val;
		occur = 1;
		children.assign(26,NULL);
	}
};

void ins(TrieNode* root, string str)
{
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'a';

		if(i==str.length()-1)
		{
			current->term = true;
		}

		if(current->children[x]!=NULL)
		{
			current = current->children[x];
			current->occur++;
		}

		else
		{
			current->children[x] = new TrieNode(str[i]);
			
			current = current->children[x];
		}

		
	}
}

bool checkStr(TrieNode* root, string str)
{
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'a';
		if(current->children[x]==NULL)return false;
		else if(i==str.length()-1 && current->term)
		{ 
			return true;
		}

		current = current->children[x];
	}

	return false;
}

string prefix(TrieNode* root,string str)
{
	TrieNode* current = root;
	string result="";
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'a';
		current = current->children[x];
		if(current->occur==1)
		{
			result+=str[i];
			return result;
		}
		else
		{
			result+=str[i];
		}
	}

	return result;
}


int main()
{
	TrieNode * root = new TrieNode('\0');
	ins(root,"hello");
	cout<<"Done"<<endl;
	cout<<checkStr(root,"hello")<<endl;
	cout<<checkStr(root,"hell")<<endl;
	cout<<checkStr(root,"dad")<<endl;
	ins(root,"dad");
	cout<<checkStr(root,"dad")<<endl;
	ins(root,"hell");
	cout<<checkStr(root,"hell")<<endl;

	cout<<prefix(root,"hello")<<endl;
	cout<<prefix(root,"dad")<<endl;
}