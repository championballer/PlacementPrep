int Solution::singleNumber(const vector<int> &A) {
    
    int current = A[0];
    for(int i=1;i<A.size();i++)current = current^A[i];
    
    return current;
}

