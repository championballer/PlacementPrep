int Solution::maxProduct(const vector<int> &A) {
    
    if(A.size()==0)return 0;
    int mx_ans = A[0];
    int current_p = 1;
    int current_n = 1;
    
    for(int i=0;i<A.size();i++)
    {
        current_n *= A[i];
        current_p *= A[i];
        int temp = current_p;
        if(current_p<current_n)
        {
            swap(current_p,current_n);
            temp = current_p;
        }
        else if(current_p<0)
        {
            current_p = 1;
        }
        else if(current_p==0)
        {
            current_p = 1;
            current_n = 1;
            
        }
        if(temp>mx_ans)mx_ans = temp;
        
        
    }
    
    return mx_ans;
}
