#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > & state, int x, int y)
{
    if(x<0 || x>=state.size() || y<0 || y>=state[0].size())return;
    if(state[x][y]==0 || state[x][y]==2)return;
    
    state[x][y] = 2;
    int tx[4] = {0,1,-1,0};
    int ty[4] = {1,0,0,-1};
    
    for(int i=0;i<4;i++)
    {
        dfs(state,x+tx[i],y+ty[i]);
    }
    
}

int black(vector<string> &A) {
    
    vector<vector<int> > state(A.size(),vector<int> (A[0].length(),0));
    for(int i=0;i<state.size();i++)
    {
        for(int j=0;j<state[i].size();j++)
        {
            if(A[i][j]=='X')state[i][j] = 1;
        }
    }
    
    int calls = 0;
    for(int i=0;i<state.size();i++)
    {
        for(int j=0;j<state[i].size();j++)
        {
            if(state[i][j]==0 || state[i][j]==2)continue;
            else
            {
                dfs(state,i,j);
                calls++;
            }
        }
    }
    
    return calls;
}

int main()
{
    int n;
    cin>>n;

    vector<string> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<<black(A)<<endl;
}
