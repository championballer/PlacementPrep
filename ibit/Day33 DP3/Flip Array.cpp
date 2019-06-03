struct Node{
  int sum;
  int elements;
};

Node helper(int total_sum,const vector<int> & A, int index)
{
    if(total_sum<0)
    {
        Node ans;
        ans.sum = INT_MAX;
        ans.elements = 0;
        return ans;
    }
    if(total_sum==0 || index==A.size())
    {
        Node ans;
        ans.sum = total_sum;
        ans.elements = 0;
        return ans;
    }
    
    Node sans1 = helper(total_sum-2*A[index], A, index+1);
    Node sans2 = helper(total_sum, A, index+1);
    
    if(sans1.sum<sans2.sum)
    {
        Node ans;
        ans.sum = sans1.sum;
        ans.elements = sans1.elements+1;
        return ans;
    }
    
    else if(sans2.sum<sans1.sum)
    {
        Node ans;
        ans.sum = sans2.sum;
        ans.elements = sans2.elements;
        return ans;
    }
    else 
    {
        Node ans;
        ans.sum = sans1.sum;
        ans.elements = min(sans1.elements+1, sans2.elements);
        return ans;
    }
}

int Solution::solve(const vector<int> &A) {
    
    int total_sum = 0;
    for(int i=0;i<A.size();i++)total_sum+=A[i];
    
    Node ans = helper(total_sum, A, 0);
    return ans.elements;
}
