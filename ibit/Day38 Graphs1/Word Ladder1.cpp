class node{
  public:
  string s;
  int dis;
  node(string s,int dis)
  {
      this->s = s;
      this->dis = dis;
  }
};

int distance(string &s1,string & s2)
{
    int dis = 0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i])dis++;
    }
    
    return dis;
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<string,bool> visited;
    for(int i=0;i<dictV.size();i++)visited[dictV[i]] = false;
    
    queue<node> pendingNodes;
    pendingNodes.push(node(start,0));
    
    while(!pendingNodes.empty())
    {
        node top = pendingNodes.front();
        pendingNodes.pop();
        
        string s = top.s;
        //cout<<s<<endl;
        visited[s] = true;
        int dis = top.dis;
        
        int togo = distance(s,end);
        if(togo==0)return dis+1;
        else if(togo==1)return dis+2;
        
        for(int i=0;i<dictV.size();i++)
        {
            if(!visited[dictV[i]] && distance(dictV[i],s)==1)pendingNodes.push(node(dictV[i],dis+1));
        }
        
    }
    
    return 0;
}
