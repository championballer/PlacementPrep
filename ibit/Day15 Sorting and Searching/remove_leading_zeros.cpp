#include<bits/stdc++.h>

using namespace std;

void remove_leading_zeros(string & s)
{
	int index = s.length();
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='0')
		{
			index=i;
			break;
		}
	}

	s = s.substr(index,s.length()-index-1);
}
int main()
{
	string s = "0";
	cout<<"Pre:"<<s<<endl;
	remove_leading_zeros(s);
	cout<<"Post:"<<s<<endl;
}