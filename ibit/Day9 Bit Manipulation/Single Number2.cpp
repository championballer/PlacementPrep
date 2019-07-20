#include<bits/stdc++.h>

int Solution::singleNumber(const vector<int> &A) {
    
    vector<int> f(32,0);
    for(int i=0;i<A.size();i++)
    {
        bitset<32> current(A[i]);
        for(int j=31,i=0;j>=0;j--,i++)
        {
            if(current[j]==1)f[i]++;
        }
    }
    
    for(int i=0;i<f.size();i++)
    {
        f[i] = f[i]%3;
    }
    
    bitset<32> aux;
    for(int i=0,j=31;i<f.size();i++,j--)
    {
        if(f[i]==1)aux[j] = 1;
    }
    int ans = aux.to_ulong();
    return ans;
}

