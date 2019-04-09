
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    cin>>in;
    
    int mx = 1;
    char prev = in[0];
    int current_length = 1;
    
    for(int i=1;i<in.length();i++)
    {
        if(in[i]!=prev)
        {
            current_length++;
            if(current_length>mx)mx = current_length;
            prev = in[i];
        }
        
        else
        {
            current_length=1;
            prev = in[i];
        }
    }
    
    cout<<mx<<endl;
}