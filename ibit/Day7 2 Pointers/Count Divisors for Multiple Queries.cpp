#include<bits/stdc++.h>

using namespace std;

int sieve[1000001];

void createSieve()
{
	memset(sieve,0,sizeof(int)*1000001);
    for(int i=1;i*i<=1000001;i++)
    {
        for(int j=i;j<=1000001;j+=i)
        {
            sieve[j]++;
        }
    }

	int sum = 0;
	for(int i=0;i<=100000;i++)
	{
		sum+=sieve[i];
		sieve[i] = sum;
	}
}

int main()
{
	//memset(sieve,0,sizeof(int)*100001);	
	createSieve();
	for(int i=0;i<=100;i++)cout<<sieve[i]<<" ";
		cout<<endl;
}