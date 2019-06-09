#include<bits/stdc++.h>

using namespace std;

void print_Array(int * arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int helper(string A)
{
	//cout<<A<<endl;
	int * pre = new int[A.length()];
	memset(pre,0,sizeof(int)*A.length());
    pre[0] = 0;
    
    for(int i=1,j=0;i<A.length();)
    {
        if(A[i]==A[j])
        {
            pre[i] = j+1;
            i++;
            j++;
            continue;
        }
        
        else
        {
            if(j==0)
            {
                pre[i] = 0;
                i++;
                continue;
            }
            
            j = pre[j-1];
        }
    }


    
    int x = pre[A.length()-1];
    int diff = A.length()-x;
    if(diff==1 || diff==A.length())return 0;
    else if(A.length()%diff==0)return 1;
    else return 0;
}
int main()
{
	string s = "lifeopretnikg";
	cout<<helper(s)<<endl;
}