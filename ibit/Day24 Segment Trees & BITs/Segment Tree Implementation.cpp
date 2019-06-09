void constructTree(vector<int> & A, int l, int r, int i,int * tree)
{
    if(l==r){
        tree[i] = A[l];
        return;
    }
    
    else
    {
        int mid = l+(r-l)/2;
        constructTree(A,l,mid,2*i,tree);
        constructTree(A,mid+1,r,2*i+1,tree);
        tree[i] = max(tree[2*i],tree[2*i+1]);
    }
}

int query(int l,int r,int lq,int rq,int i, int * tree)
{
    if(l==lq && r==rq)return tree[i];
    else
    {
        int mid = l+(r-l)/2;
        if(lq<=mid && rq<=mid)
        {
            return query(l,mid,lq,rq,2*i,tree);
        }
        
        else if(lq>mid && rq>mid)
        {
            return query(mid+1,r,lq,rq,2*i+1,tree);
        }
        
        else
        {
            return max(query(l,mid,lq,mid,2*i,tree),query(mid+1,r,mid+1,rq,2*i+1,tree));
        }
    }
}