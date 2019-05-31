int helper(const string & A, const string & B, int i,int j,vector<vector<int> >& mem,vector<vector<int> >& vis)
{
    //cout<<"i:"<<i<<" "<<"j:"<<j<<endl;
    //cout<<A.length()<<" "<<B.length()<<endl;
    if(mem[i][j])return mem[i][j];
    if(i==A.length() && j==B.length())
    {
        //cout<<"1 con ent"<<endl;
        vis[i][j] = 1;
        mem[i][j] = 1;
        return 1;
    }
    if(j==B.length())
    {
        //cout<<"2 con ent"<<endl;
        vis[i][j] = 1;
        mem[i][j] = 0;
        return 0;
    }
    if(i==A.length())
    {
        //cout<<"3 con ent"<<endl;
        int current = j;
        while(B[current]=='*')
        {
            if(current==B.length())
            {
                vis[i][j] = 1;
                mem[i][j] = 1;
                return 1;
            }
            
            current++;
        }
        
        if(current==B.length())
            {
                vis[i][j] = 1;
                mem[i][j] = 1;
                return 1;
            }
        
        vis[i][j] = 1;
        mem[i][j] = 0;
        return 0;
    }
    
    int sans = 0;
    if(B[j]!='?' && B[j]!='*')
    {
        if(A[i]==B[j])
        {   
            if(!vis[i+1][j+1])sans = helper(A,B,i+1,j+1,mem,vis);
            else sans = mem[i+1][j+1];
        }
        else
        {
            sans = 0;
        }
        
        vis[i][j] = 1;
        mem[i][j] = sans;
        return mem[i][j];
    }
    
    else if(B[j]=='?')
    {
        if(!vis[i+1][j+1])sans =  helper(A,B,i+1,j+1,mem,vis);
        else sans = mem[i+1][j+1];
        vis[i][j] = 1;
        mem[i][j] = sans;
        return sans;
    }
    else
    {
        int sans1 = 0;
        int sans2 = 0;
        if(!vis[i+1][j])sans1 = helper(A,B,i+1,j,mem,vis);
        else sans1 = mem[i+1][j];
        
        if(!vis[i][j+1])sans2 = helper(A,B,i,j+1,mem,vis);
        else sans2 = mem[i][j+1];
        vis[i][j] = 1;
        mem[i][j] =  sans1||sans2;
        return mem[i][j];
    }
}


int Solution::isMatch(const string A, const string B) {

    vector<vector<int> > mem(A.length()+1,vector<int>(B.length()+1));
    vector<vector<int> > vis(A.length()+1,vector<int>(B.length()+1));
    return helper(A,B,0,0,mem,vis);
    
}
