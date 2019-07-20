vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    
    vector<int> aux(A.size()+1,0);
    for(int i=1;i<=A.size();i++)
    {
        aux[i] = aux[i-1]+A[i-1];
    }
    
    vector<vector<int> > result;
    for(int i=0;i<B.size();i++)
    {
        int l = B[i][0];
        int r = B[i][1];
        
        vector<int> current;
        current.push_back((aux[r]-aux[l-1])&1);
        current.push_back((r-l+1)-(aux[r]-aux[l-1]));
        result.push_back(current);
    }
    return result;
}

