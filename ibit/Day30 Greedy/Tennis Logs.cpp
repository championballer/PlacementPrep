string Solution::solve(int A, vector<int> &B) {
    
    int play1 = 1;
    int play2 = 2;
    int spec = 3;
    
    for(int i=0;i<A;i++)
    {
        int current = B[i];
        if(play1!=current && play2!=current)return "No";
        else if(play1==current)
        {
            int temp = play2;
            play2 = spec;
            spec = temp;
        }
        
        else
        {
            int temp = play1;
            play1 = spec;
            spec = temp;
        }
    }
    
    return "Yes";
}
