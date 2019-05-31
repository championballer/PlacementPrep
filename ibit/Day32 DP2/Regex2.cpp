


int helper(const string & A, const string & B, int i,int j,vector<vector<int> >& mem)
{
    if(mem[i][j])return mem[i][j];
    if(i==A.length() && j==B.length())
    {
        mem[i][j] = 1;
        return 1;
    }
    if(j==B.length())
    {
        mem[i][j] = 0;
        return 0;
    }
    if(i==A.length())
    {
        int current = j;
        while(B[current]=='*')
        {
            if(current==B.length())
            {
                mem[i][j] = 1;
                return 1;
            }
            
            current++;
        }
        
        if(current==B.length())
            {
                mem[i][j] = 1;
                return 1;
            }
    
        mem[i][j] = 0;
        return 0;
    }
    
    int sans = 0;
    if(B[j]!='?' && B[j]!='*')
    {
        if(A[i]==B[j])
        {   
            sans = helper(A,B,i+1,j+1,mem);
            
        }
        else
        {
            sans = 0;
        }
        
        mem[i][j] = sans;
        return mem[i][j];
    }
    
    else if(B[j]=='?')
    {
        sans =  helper(A,B,i+1,j+1,mem);
        mem[i][j] = sans;
        return sans;
    }
    else
    {
        int sans1 = 0;
        int sans2 = 0;
        sans1 = helper(A,B,i+1,j,mem);
        sans2 = helper(A,B,i,j+1,mem);
        
        mem[i][j] =  sans1||sans2;
        return mem[i][j];
    }
}


int Solution::isMatch(const string A, const string B) {

    vector<vector<int> > mem(A.length()+1,vector<int>(B.length()+1));
    return helper(A,B,0,0,mem);
    
}
