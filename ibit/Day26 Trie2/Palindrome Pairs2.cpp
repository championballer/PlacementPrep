bool checkPalindrome(string A)
{
    for(int i=0,j=A.length()-1;i<=j;i++,j--)
    {
        if(A[i]!=A[j])return false;
    }
    
    return true;
}

vector<vector<int> > Solution::solve(vector<string> &A) {
    
    unordered_map<string,int> dict;
    for(int i=0;i<A.size();i++)
    {
        string current = A[i];
        reverse(current.begin(),current.end());
        
        dict[current] = i;
    }
    vector<vector<int> > result;
    for(int k=0;k<A.size();k++)
    {
        int size = A[k].size();
        for(int i=1;i<=size;i++)
        {
            int j = size-i;
            string left = A[k].substr(0,i);
            string right = A[k].substr(i,j);
            
            if(checkPalindrome(left))
            {
                if(dict.count(right) && dict[right]!=k)
                {
                    vector<int> sans;
                    sans.push_back(dict[right]);
                    sans.push_back(k);
                    result.push_back(sans);
                }
            }
            
            if(checkPalindrome(right))
            {
                if(dict.count(left) && dict[left]!=k)
                {
                    vector<int> sans;
                    
                    sans.push_back(k);
                    sans.push_back(dict[left]);
                    result.push_back(sans);
                }
            }
        }
    }
    
    return result;
}
