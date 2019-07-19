void helper(vector<int> & A, int B, int i, vector<int> & current, set<vector<int> >& result)
{
    //cout<<i<<" "<<B<<endl;
    if(B<0)return;
    if(B==0)
    {
        // cout<<B<<endl;
        // for(int i=0;i<current.size();i++)cout<<current[i]<<" ";
        // cout<<endl;
        sort(current.begin(),current.end());
        result.insert(current);
        
        return;
    }
    if(i<0)return;
    
    
    //cout<<B<<" "<<A[i]<<endl;
    vector<int> temp = current;
    helper(A,B,i-1,current,result);
    temp.push_back(A[i]);
    helper(A,B-A[i],i-1,temp,result);
    
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > result;
    vector<int> current;
    set<vector<int> > aux;
    helper(A,B,A.size()-1,current,aux);
    for(auto it = aux.begin();it!=aux.end();it++)
    {
        vector<int> current = *it;
        result.push_back(current);
    }
    return result;
}

