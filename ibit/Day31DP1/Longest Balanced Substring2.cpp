map<pair<int,int>,pair<bool,int> > ourmap;

bool check(const string & A, int i, int j)
{
    if((A[i]=='(' && A[j]==')') || (A[i]=='[' && A[j]==']') || (A[i]=='{' && A[j]=='}') || (A[i]=='<' && A[j]=='>'))
    {
        return true;
    }
    
    else return false;
}
int Solution::LBSlength(const string A) {
    
    ourmap.clear();
    for(int i=0,j=0;i<A.length();i++,j++)
    {
        ourmap[make_pair(i,j)] = make_pair(0,0);
    }
    
    for(int k=1;k<A.length();k++)
    {
        for(int i=0,j=k;j<A.length();i++,j++)
        {
            pair<int,int> current = make_pair(i,j);
            if(check(A,i,j))
            {
                if(i+1==j)
                {
                    ourmap[current] = make_pair(1,2);
                }
                
                else
                {
                    pair<bool,int> sans1;
                    sans1 = ourmap[make_pair(i+1,j-1)];
                    if(sans1.first)
                    {
                        ourmap[current] = make_pair(1,sans1.second+2);
                    }
                
                    else ourmap[current] = make_pair(0,sans1.second);    
                }
            }
            
            for(int k=i+1;k<=j;k++)
            {
                pair<bool,int> sans1 = ourmap[make_pair(i,k)];
                if(k+1>=j)break;
                pair<bool,int> sans2 = ourmap[make_pair(k+1,j)];
                if(sans1.first && sans2.first)
                {
                    ourmap[current].first = 1;
                    ourmap[current].second = max(ourmap[current].second,sans1.second+sans2.second);
                }
                else ourmap[current].second = max(ourmap[current].second,max(sans1.second,sans2.second));
            }
            
            pair<bool,int> sans1 = ourmap[make_pair(i+1,j)];
            pair<bool,int> sans2 = ourmap[make_pair(i,j-1)];
            ourmap[current].second = max(ourmap[current].second,max(sans1.second,sans2.second));
        }
    }
    
    return ourmap[make_pair(0,A.length()-1)].second;
}
