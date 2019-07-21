#include<bits/stdc++.h>
using namespace std;

bool dp[10][100000];

void mark(int i,int a)
{
    while(a!=0)
    {
        int x = a%10;
        dp[x][i] = 1;
        a/=10;
    }
}
int solve (vector<int> arr) {
   // Write your code here.
   
   int result = 0;
   for(int i=0;i<arr.size();i++)
   {
       mark(i,arr[i]);
   }
   
   for(int i=0;i<10;i++)
   {
       int local_max = 0;
       int current = 0;
       for(int j=0;j<arr.size();j++)
       {
           if(dp[i][j]==1)
           {
               current++;
               if(current>local_max)local_max = current;
           }
       }
       
       if(local_max>result)result = local_max;
   }
   
   return result; 
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    int out_;
    out_ = solve(arr);
    cout << out_;
}
