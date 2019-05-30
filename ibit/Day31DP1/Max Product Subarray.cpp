int Solution::maxProduct(const vector<int> &A) {
    
    if(A.size()==0)return 0;
    int gmax = INT_MIN;
    int lmax = 0;
    int lmaxn = 0;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            lmax = 0;
            lmaxn = 0;
            
            if(lmax>gmax)gmax = lmax;
        }
        
        else if(A[i]>0)
        {
            if(lmax==0)lmax=A[i];
            else lmax*=A[i];
            lmaxn*=A[i];
            
            if(lmax>gmax)gmax=lmax;
        }
        
        else
        {
            if(lmaxn==0)
            {
                int temp = lmaxn;
                if(temp>lmax)lmax = temp;
                lmaxn = min(lmax*A[i],A[i]);
            }
            
            else
            {
                int temp = lmaxn*A[i];
                if(temp>lmax)lmax = temp; 
                lmaxn = A[i];
            }
            
            if(lmax!=0 && lmax>gmax)gmax=lmax;
            if(lmaxn>gmax)gmax=lmaxn;
        }
        
        //cout<<i<<" "<<"lmax:"<<lmax<<" lmaxn:"<<lmaxn<<" "<<endl;
    }
    
    return gmax;
}
