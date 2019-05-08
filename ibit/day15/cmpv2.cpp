#include<bits/stdc++.h>

using namespace std;

void remove_leading_zeros(string & str)
{
	cout<<str<<endl;
	int index = str.length();
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!='0')
		{
			index = i;
			break;
		}
	}

	str = str.substr(index,str.length()-index);
}

int cmp(string & s1, string s2)
{
	if(s1.length()==0 && s2.length()==0)return 0;
	else if(s1.length()==0 || s1.length()<s2.length() || s1.compare(s2)<0)return -1;
	else if(s2.length()==0 || s2.length()<s1.length() || s1.compare(s1)>0)return 1;
	else return 0; 
}

int cmpversion(string & s1, string & s2)
{
	for(int i=0,j=0;i<s1.length() || j<s2.length();)
	{
		string part1 = "";
		string part2 = "";
		while(s1[i]!=' ' && i<s1.length())
		{
			part1+=s1[i];
			i++;
		}

		while(s2[j]!=' ' && j<s2.length())
		{
			part2+=s2[j];
			j++;
		}
		remove_leading_zeros(part1);
		remove_leading_zeros(part2);
		int ans = cmp(part1,part2);
		if(ans)return ans;
		i++;
		j++;
	}

	return 0;
}

int main()
{
	string str = "2";
	string str2 = "2.0";
	cout<<cmpversion(str,str2)<<endl;

}