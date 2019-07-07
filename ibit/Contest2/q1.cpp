#define MOD 1000000007

int dp[500][500];

int solve(int A, int B)
{
    if(dp[A][B]!=-1)return dp[A][B];
    if(A<=0)return 0;
    if(B==0)return 2;
    if(A==1 && B==1)return 3;
    
    int ans = 0;
    for(int i=0;i<A;i++)
    {
        int sans1 = solve(A-i-1,B-1);
        int sans2 = solve(i,B-i);
        ans = (ans+(sans1%MOD)+(sans2%MOD))%MOD;
    }
    
    dp[A][B] = (ans+2)%MOD;
    return dp[A][B];
    
}

int main()
{
	int a, b;
	cin>>a>>b;

	cout<<solve)
}
