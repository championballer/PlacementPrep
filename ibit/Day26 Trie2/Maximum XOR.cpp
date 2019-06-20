#include<bits/stdc++.h>

using namespace std;

class TrieNode{
public:
	char val;
	vector<TrieNode*> children;

	TrieNode(char val)
	{
		this->val = val;
		children.assign(2,NULL);
	}
};

void ins(TrieNode* root,string str)
{
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'0';

		if(current->children[x]==NULL)
		{
			current->children[x] = new TrieNode(str[i]);
		}

		current = current->children[x];
	}
}

string mxor(TrieNode* root,string str,int v)
{
	// cout<<v<<endl;
	string mx = "";
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'0';
		// cout<<current->val<<" ";
		// cout<<x<<endl;
		if(current->children[1-x]==NULL && current->children[x]==NULL)
		{
			return mx;
		}

		else if(current->children[1-x]==NULL)
		{
			current = current->children[x];
			if(current!=NULL)
			mx+='0';
			
		}

		else if(current->children[1-x]!=NULL)
		{
			current = current->children[1-x];
			mx+='1';
		}
	}
	//cout<<mx<<endl;
	return mx;
}

int main()
{
	vector<int> in{5,17,100,11};
	TrieNode* root = new TrieNode('\0');
	for(int i=0;i<in.size();i++)
	{
		string c = bitset<8>(in[i]).to_string();
		//cout<<c<<endl;
		ins(root,c);
	}


	unsigned long mx = 0;
	for(int i=0;i<in.size();i++)
	{
		string c = bitset<8>(in[i]).to_string();
		string val = mxor(root,c,in[i]);
		unsigned long decimal = bitset<8>(val).to_ulong();
		//cout<<decimal<<endl;
		if(mx<decimal)
		{
			mx = decimal;
		}
	}

	cout<<mx<<endl;
}