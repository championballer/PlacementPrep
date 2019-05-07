#include<bits/stdc++.h>

using namespace std;

void preprocess(string & ptr, int * arr)
{
	arr[0] = 0;
	int j = 0;
	for(int i=1;i<ptr.length();)
	{
		if(ptr[j]==ptr[i])
		{
			arr[i] = j+1;
			i++;
			j++;
		}

		else
		{

		}
	}
}

int main()
{
	string ptr, s;

	cin>>ptr;
	cin>>s;

	int * ptr_arr = new int[ptr.length()];
	memset(ptr_arr,0,sizeof(int)*ptr.length());

	preprocess()

}