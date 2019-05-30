bool checkValidity(string s)
{
    if(s.length()==1)
    {
        if(s[0]=='0')return false;
        else return true;
    }
    
    else if(s.length()==2)
    {
        if(s[0]=='1' || s[0]=='2')
        {
            if(s[0]=='1')return true;
            else{
                if(s[1]>='0' && s[1]<='6')return true;
                else return false;
            }
        }
        else return false;
    }
}

int Solution::numDecodings(string A) {

    if(A.length()==0)return 0;
    
    vector<int> dp(A.length());
    
    if(checkValidity(A.substr(0,1))){
        dp[0] =1;
    }
    else return 0;
    if(A.length()==1)return dp[0];
    
    int sans1 = 0;
    int sans2 = 0;
    
    if(checkValidity(A.substr(1,1)))sans1=1;
    if(checkValidity(A.substr(0,2)))sans2=1;
    
    dp[1] = sans1+sans2;
    if(A.length()==2)return dp[1];
    
    for(int i=2;i<A.length();i++)
    {
        if(checkValidity(A.substr(i,1)))
        {
            sans1 = dp[i-1];
        }
        
        else sans1 = 0;
        
        if(checkValidity(A.substr(i-1,2)))
        {
            sans2 = dp[i-2];
        }
        
        else sans2 = 0;
        
        dp[i] = sans1+sans2;
    }
    
    return dp[A.size()-1];
    
}

