#include<bits/stdc++.h>

using namespace std;

void remove_leading_zeros(string & s1,string & s2)
{
	int index = s1.length();
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!='0')
		{
			index=i;
			break;
		}
	}

	if(index==s1.length())s1 = "";
	else s1 = s1.substr(index,s1.length()-index-1);

	index = s2.length();
	for(int i=0;i<s2.length();i++)
	{
		if(s2[i]!='0')
		{
			index=i;
			break;
		}
	}

	if(index==s2.length())s2 = "";
	else s2 = s2.substr(index,s2.length()-index-1);
}

int cmpString(string s1,string s2)
{
	cout<<s1<<" "<<s2<<" "<<s1.compare(s2)<<endl;
 	if(s1.length()==0 || s2.length()>s1.length() || s1.compare(s2)<0)return -1;
 	else if(s2.length()==0 || s1.length()>s2.length() || s1.compare(s2)>0)return 1;
 	return 0;
	
}

int compareVersion(string A, string B) {
    
    string part1 = "";
    string part2 = "";
    
    for(int i=0,j=0;i<A.length() || j<B.length();)
    {
        part1="";
        part2="";
        while(A[i]!='.' && i<A.length())
        {
            part1+=A[i];
            i++;
        }
        
        while(B[j]!='.' && j<B.length())
        {
            part2+=B[j];
            j++;
        }
        remove_leading_zeros(part1,part2);
        int index = part1.length();
		for(int i=0;i<part1.length();i++)
		{
			if(part1[i]!='0')
			{
				index=i;
				break;
			}
		}

		if(index==part1.length())part1 = "";
		else part1 = part1.substr(index,part1.length()-index-1);

		index = part2.length();
		for(int i=0;i<part2.length();i++)
		{
			if(part2[i]!='0')
			{
				index=i;
				break;
			}
		}

		if(index==part2.length())part2 = "";
		else part2 = part2.substr(index,part2.length()-index-1);
        //remove_leading_zeros(part2);
        //cout<<part1<<" "<<part2<<endl;
        int ans = cmpString(part1,part2);
        //cout<<ans<<endl;
        if(ans)return ans;
        i++;
        j++;
        
    }
    
    return 0;
}


int main()
{
	string str1 = "1.21";
	string str2 = "1.0";

	cout<<compareVersion(str1,str2)<<endl;
}