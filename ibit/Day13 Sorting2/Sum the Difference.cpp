#define MOD 1000000007

long long power(int x)
{
    long long ans = 1;
    for(int i=0;i<x;i++)ans = ((long long)ans * 2)%MOD;
    return ans;
}

int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    long long ans = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            long long diff = (A[j]-A[i])%MOD;
            long long mul = j-i;
            if(mul!=1)mul = ((long long)(power(mul-1)))%MOD;
            diff = (diff*(mul%MOD))%MOD;
            ans = ((long long)ans + diff%MOD)%MOD;
        }
    }
    
    return ans;
}
