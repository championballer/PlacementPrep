bool check(vector<vector<char> > & board, int x, int y, char c)
{
    
    int n = board.size();
    for(int i=0,j=y;i<n;i++)
    {
        if(i==x)continue;
        if(board[i][j]==c)return false;
    }
    
    for(int i=x,j=0;j<n;j++)
    {
        if(j==y)continue;
        if(board[i][j]==c)return false;
    }
    
    int row = (x/3)*3;
    int col = (y/3)*3;
    for(int i=row;i<row+3;i++)
    {
        for(int j=col;j<col+3;j++)
        {
            
            if(i==x && j==y)continue;
            if(board[i][j]==c)return false;
        }
    }
    
    return true;
}

bool helper(vector<vector<char> > & board, int x, int y)
{
    
    int n = board.size();
    if(x==n)return true;

    if(board[x][y]!='.')
    {
        if(y!=n-1)return helper(board,x,y+1);
        else return helper(board,x+1,0);
    }
    
    bool ans = false;
    for(int i=1;i<=9;i++)
    {
        char c = i+'0';
        board[x][y] = c;
        bool q = check(board,x,y,c); 
        
        if(q)
        {
            
            if(y!=n-1)
            {
                ans = helper(board,x,y+1);
            }
            
            else
            {
                ans = helper(board,x+1,0);
            }
            
            if(ans)return true;
        }
        board[x][y]='.';
    }
    
    return false;
    
    
}
/*
9 9 5 3 . . 7 . . . . 6 . . 1 9 5 . . . . 9 8 . . . . 6 . 8 . . . 6 . . . 3 4 . .8 . 3 . . 1 7 . . . 3 . . . 6 . 6 . . . . 2 8 . . . . 4 1 9 . . 5 . . . . 8 . . 7 9
*/
void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    bool ans = helper(A,0,0);
    //cout<<ans<<endl;
    return;
    
}

