vector<int> Solution::solve(int A, int B, int C, int D) {
    
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    
    vector<int> result;
    while(result.size()!=D)
    {
        int t = *s.begin();
        s.erase(s.begin());
        result.push_back(t);
        s.insert(t*A);
        s.insert(t*B);
        s.insert(t*C);
    }
    
    return result;
}
