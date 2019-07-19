bool check(vector<string>& board, int x,int y)
{
    //cout<<"func1 "<<x<<" "<<y<<endl;
    int n = board.size();
    for(int i=0,j=y;i<n;i++)
    {
        if(i==x)continue;
        else if(board[i][j]=='Q')return false;
    }
    //cout<<"cp1"<<endl;
    for(int i=x,j=0;j<n;j++)
    {
        if(j==y)continue;
        else if(board[i][j]=='Q')return false;
    }
    //cout<<"cp2"<<endl;
    for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')return false;
    }
    //cout<<"cp3"<<endl;
    for(int i=x+1,j=y+1;i<n && j<n;i++,j++)
    {
        if(board[i][j]=='Q')return false;
    }
    //cout<<"cp4"<<endl;
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]=='Q')return false;
    }
    //cout<<"cp5"<<endl;
    for(int i=x+1,j=y-1;i<n && j>=0;i++,j--)
    {
        if(board[i][j]=='Q')return false;
    }
    //cout<<"cp6"<<endl;
    
    return true;
}

void helper(vector<vector<string> > & result,vector<string> & board, int x,int y)
{
    //cout<<"func2 "<<x<<" "<<y<<endl;
    int n = board.size();
    if(x==n)
    {
        result.push_back(board);
        return;
    }
    
    else if(y==n)return;
    
    if(check(board,x,y))
    {
        board[x][y]='Q';
        helper(result,board,x+1,0);
        board[x][y]='.';
    }
    
    helper(result,board,x,y+1);
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string a = "";
    for(int i=0;i<A;i++)a+='.';
    vector<string> current(A,a);
    vector<vector<string> > result;
    helper(result,current,0,0);
    return result;
    
}

