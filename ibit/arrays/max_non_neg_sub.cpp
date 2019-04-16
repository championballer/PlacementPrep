typedef long long ll;

vector<int> Solution::maxset(vector<int> &A) {
    
    ll mx_sum = INT_MIN;
    vector<int> result;
    vector<int> current_array;
    ll current_sum = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {
            current_sum+=A[i];
            current_array.push_back(A[i]);
            
            if(i==A.size()-1)
            {
               if(current_sum>mx_sum)
                {
                    mx_sum = current_sum;
                    result = current_array;
                } 
            }
        }
        
        else
        {
            if(current_sum>mx_sum)
            {
                mx_sum = current_sum;
                result = current_array;
            }
            
            current_sum = 0;
            current_array.clear();
        }
    }
    
    return result;
}
