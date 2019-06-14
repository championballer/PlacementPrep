#include<bits/stdc++.h>

using namespace std;

vector<int> solve(int A, vector<vector<int> > &B, int C) {
    vector<pair<int,int> > neighbours[A];
    for(int i=0;i<B.size();i++)
    {
        int x = B[i][0];
        int y = B[i][1];
        int w = B[i][2];
        
        neighbours[x].push_back(make_pair(y,w));
        neighbours[y].push_back(make_pair(x,w));
    }

    vector<int> distance(A,INT_MAX);
    vector<bool> visited(A,0); 
    distance[C] = 0;
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,C));
    
    while(!pq.empty())
    {
    	pair<int,int> top = pq.top();
    	pq.pop();
    	int node = top.second;
    	int dis = top.first;
    	
    	if(visited[node])continue;
    	visited[node] = true;
    	
    	for(int i=0;i<neighbours[node].size();i++)
    	{
    		pair<int,int> m = neighbours[node][i];
    		int n = m.first;
    		int e = m.second;
    		if(dis+e<distance[n])
    		{
    			pq.push(make_pair(dis+e,n));
    			distance[n] = dis+e;
    		}
    	}

    }
    
    return distance;
}


int main()
{

	int n;
	cin>>n;
	int edges;
	cin>>edges;
	vector<vector<int > > B(edges,vector<int>(3));
	for(int i=0;i<B.size();i++)
	{
		cin>>B[i][0];
		cin>>B[i][1];
		cin>>B[i][2];
	}

	int C;
	cin>>C;

	vector<int> ans = solve(n,B,C);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}