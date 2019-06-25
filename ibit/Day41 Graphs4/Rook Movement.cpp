class node{
  public:
  int x;
  int y;
  int d;
  
  node(int x,int y,int d)
  {
      this->x = x;
      this->y = y;
      this->d = d;
  }
  
  bool operator < (const node &g) const {
        return d > g.d;
    }
};

bool check(int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)return 0;
    else return 1;
}

int Solution::solve(int A, int B, int C, int D, vector<string> &E) {
    vector<vector<int> > v(E.size(),vector<int>(E[0].length(),INT_MAX));
    int sx = A-1;
    int sy = B-1;
    
    int dx = C-1;
    int dy = D-1;
    
    int tx[4] = {-1,0,1,0};
    int ty[4] = {0,1,0,-1};
    
    priority_queue<node> pq;
    pq.push(node(sx,sy,0));
    while(!pq.empty() && v[dx][dy]==INT_MAX)
    {
        node t = pq.top();
        pq.pop();
        int x = t.x;
        int y = t.y;
        int d = t.d;
        if(v[x][y]!=INT_MAX)continue;
        else v[x][y] = d;
        for(int i=0;i<4;i++)
        {
            int x1 = x;
            int y1 = y;
            int d1 = 0;
            while(true)
            {
                int x2=x1+tx[i];
                int y2=y1+ty[i];
                //cout<<x2<<" "<<y2<<endl;
                
                if(check(x2,y2,E.size(),E[0].length()) && E[x2][y2]!='1')
                {
                    x1 = x2;
                    y1 = y2;
                }
                
                else break;
            }
            
            if(d1>0)
            {
                pq.push(node(x1,y1,d+1));
            }
            
        }
    }
    
    if(v[dx][dy]==INT_MAX)return -1;
    else return v[dx][dy];
}
