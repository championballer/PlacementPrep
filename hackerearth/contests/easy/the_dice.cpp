#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int girls=0;
    int flag=0;
    
    for(int i=0;i<s.length();i++)
    {
        if(i==s.length()-1 && s[i]=='6')
        {
            flag=1;
            break;
        }
        
        else
        {
            if(s[i]!='6')girls++;
        }
    }
    
    if(!flag)
    cout<<girls;

    else cout<<-1<<endl;
}