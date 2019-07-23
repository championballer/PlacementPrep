pair<int,int> dp[10000][100];

pair<int,int> helper(const vector<int>& A, int sum, int i)
{
    //cout<<sum<<" "<<i<<endl;
    if(sum==0)
    {
        return make_pair(0,0);
    }
    if(i==A.size())
    {
        return make_pair(0,0);
    }
    
    if(dp[sum][i]!=make_pair(-1,-1))return dp[sum][i];
    pair<int,int> sans1 = make_pair(0,INT_MAX);
    pair<int,int> sans2;
    if(sum-A[i]>=0)
    {
        sans1 = helper(A,sum-A[i],i+1);
        sans1.first = sans1.first+A[i];
        sans1.second = sans1.second+1;
    }
    sans2 = helper(A,sum,i+1);
    pair<int,int> ans;
    if(sans1.first>sans2.first)ans = sans1;
    else if(sans1.first<sans2.first)ans = sans2;
    else
    {
        if(sans1.second<sans2.second)ans = sans1;
        else ans = sans2;
    }
    dp[sum][i] = ans;
    return dp[sum][i];
}

//7 5 4 6 8 7 2 3
//6 6 2 5 4 5 1 6
int Solution::solve(const vector<int> &A) {

    int sum = 0;
    for(int i=0;i<A.size();i++)sum+=A[i];
    for(int i=0;i<sum;i++)
    {
        for(int j=0;j<A.size();j++)dp[i][j] = make_pair(-1,-1);
    }
    return helper(A,sum/2,0).second;
}

