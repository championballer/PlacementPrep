int Solution::isMatch(const string A, const string B) {
    
    //vector<vector<bool> > dp(A.length()+1,vector<bool> (B.length()+1,0));
    
    vector<int> prev(B.length()+1,0);
    vector<int> current(B.length()+1,0);
    //dp[A.length()][B.length()] = 1;
    // for(int i=A.length()-1;i>=0;i--)
    // {
    //     dp[i][B.length()] = 0;
    // }
    
    prev[B.length()] = 1;
    for(int i=B.length()-1;i>=0;i--)
    {
        if(B[B.length()-i-1]=='*')prev[i] = prev[i+2];
        else prev[i] = 0;
    }
    
    for(int i=A.length()-1;i>=0;i--)
    {
        for(int j=B.length()-1;j>=0;j--)
        {
            if(B[B.length()-j-1]>='a' && B[B.length()-j-1]<='z')
            {
               if(B[B.length()-j-1]==A[A.length()-i-1])current[j] = prev[j+1]; 
               else current[j] = 0;
            }
            
            else if(B[B.length()-j-1]=='.')
            {
                current[j] = prev[j+1];
            }
            
            else if(B[B.length()-j-1]=='*')
            {
                if(B[B.length()-j-2]==A[A.length()-i-1] || B[B.length()-j-2]=='.')
                {
                    current[j] = prev[j+2]||prev[j];
                }
        
                else current[j] = current[j+2];
            }
        }
        
        prev = current;
    }
    
    
    return current[0];
}