#include<bits/stdc++.h>

using namespace std;

bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
	}

	return true;
}

int main()
{
	int diff = 2;
	int last_prime = 2;
	for(int i=2;i<INT_MAX;i++)
	{
		if(!prime(i))
		{
			if(i-last_prime>246)
			{
				cout<<"Missed"<<endl;
			}
		}

		else
		{
			cout<<i<<endl;
			last_prime = i;
		}
	}
}