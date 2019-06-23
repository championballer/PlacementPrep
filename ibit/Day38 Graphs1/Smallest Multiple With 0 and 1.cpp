string Solution::multiple(int A) {
    
    vector<char> v(A);
    vector<int> p(A,-1);
    
    int i = 1%A;
    v[i] = '1';
    p[i] = -2;
    queue<int> q;
    while(i!=0)
    {
        int aux1 = ((i%A)*(10%A))%A;
        if(p[aux1]==-1)
        {
            p[aux1] = i;
            v[aux1] = '0';
            q.push(aux1);
        }
        
        // if(aux1==0)
        // {
        //     i = 0;
        //     break;
        // }
        
        int aux2 = ((aux1%A)+1)%A;
        if(p[aux2]==-1)
        {
            p[aux2] = i;
            v[aux2] = '1';
            q.push(aux2);
        }
        
        // if(aux2==0)
        // {
        //     i=0;
        //     break;
        // }
        
        i = q.front();
        q.pop();
    }
    //cout<<"Cond1"<<endl;
    //i = 0;
    string ans = "";
    // for(int i=0;i<A;i++)cout<<p[i]<<" ";
    // cout<<endl;
    while(p[i]!=-2)
    {
        // cout<<ans<<endl;
        // cout<<i<<endl;
        ans+=v[i];
        i=p[i];
    }
    
    ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
