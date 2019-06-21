map<pair<int,int>,pair<bool,int> > ourmap;

pair<bool,int> helper(const string A, int i,int j)
{
    //cout<<i<<" "<<j<<endl;   
    pair<int,int> current = make_pair(i,j);
    if(ourmap.count(current))return ourmap[current];
    if(i==j)
    {
        ourmap[current] = make_pair(0,0);
        return ourmap[current];
    }
    
    if(i>j)return make_pair(0,0);
    ourmap[current] = make_pair(0,0);
    if((A[i]=='(' && A[j]==')') || (A[i]=='[' && A[j]==']') || (A[i]=='{' && A[j]=='}') || (A[i]=='<' && A[j]=='>'))
    {
        if(i+1==j)
        {
            ourmap[current] = make_pair(1,2);
            
        }
        
        else
        {
            pair<bool,int> sans1;
            sans1 = helper(A,i+1,j-1);
            if(sans1.first)
            {
                ourmap[current] = make_pair(1,sans1.second+2);
            }
            
            else ourmap[current] = make_pair(0,sans1.second);    
        }
        
    }
    
    for(int k=i+1;k<=j;k++)
    {
        
        pair<bool,int> sans1 = helper(A,i,k);
        pair<bool,int> sans2 = helper(A,k+1,j);
        if(sans1.first && sans2.first)
        {
            ourmap[current].first = 1;
            ourmap[current].second = max(ourmap[current].second,sans1.second+sans2.second);
        }
        else ourmap[current].second = max(ourmap[current].second,max(sans1.second,sans2.second));
    }
    
    pair<bool,int> sans1 = helper(A,i+1,j);
    pair<bool,int> sans2 = helper(A,i,j-1);
    ourmap[current].second = max(ourmap[current].second,max(sans1.second,sans2.second));
    //cout<<i<<" "<<j<<" "<<ourmap[current].second<<endl;
    return ourmap[current];
    
}
//<>]][[}{}()[][{>)((]({
int Solution::LBSlength(const string A) {

    ourmap.clear();
    return helper(A,0,A.length()-1).second;
    
}
