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