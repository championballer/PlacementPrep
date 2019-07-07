#include<bits/stdc++.h>

using namespace std;

bool checkPrime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    
    return true;
}

void createSieve(bool * sieve,int size)
{
    for(int i=2;i<size;i++)
    {
        if(sieve[i])
        {
            bool ans = checkPrime(i);
            sieve[i] = ans;
            for(int j=2*i;j<size;j+=i)
            {
                sieve[j] = false;
            }
        }
    }
}

vector<int> solve(const int A) {
    
    vector<int> result;
    if(A==0)return result;
    else result.push_back(1);
    bool * sieve = new bool[1300000];
    memset(sieve,true,sizeof(bool)*1300000);
    
    sieve[0] = false;
    sieve[1] = false;
    
    createSieve(sieve,1300000);
    
    int counter = 1;
    for(int i=2;i<1300000 && counter<A;i++)
    {
        if(sieve[i] && counter<A)
        {
            result.push_back(i);
            counter++;
        }
    }
    
    return result;
 }

int main()
{
    int a;
    cin>>a;

    vector<int> ans = solve(a);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}