#include<bits/stdc++.h>

using namespace std;

void mark(int ** matrix, int A, int B,int x, int y, int R)
{

	queue<pair<pair<int, int>,int> > pendingNodes;

	pendingNodes.push(make_pair(make_pair(x,y),0));

	while(!pendingNodes.empty())
	{
		auto top = pendingNodes.front();
		pendingNodes.pop();
		int i = top.first.first;
		int j = top.first.second;
		int dis = top.second;
		cout<<i<<" "<<j<<" "<<dis<<endl;
		matrix[i][j] = 1;
		if(dis==R)continue;
		else
		{
			if(i+1<A)pendingNodes.push(make_pair(make_pair(i+1,j),dis+1));
			if(j+1<B)pendingNodes.push(make_pair(make_pair(i,j+1),dis+1));
			if(i+1<A && j+1<B)pendingNodes.push(make_pair(make_pair(i+1,j+1),dis+1));
			if(i-1>=0)pendingNodes.push(make_pair(make_pair(i-1,j),dis+1));
			if(j-1>=0)pendingNodes.push(make_pair(make_pair(i,j-1),dis+1));
			if(i-1>=0 && j-1>=0)pendingNodes.push(make_pair(make_pair(i-1,j-1),dis+1));
			if(i-1>=0 && j<B)pendingNodes.push(make_pair(make_pair(i-1,j+1),dis+1));
			if(i<A && j-1>=A)pendingNodes.push(make_pair(make_pair(i+1,j-1),dis+1));
		}


	}
}

bool bfs(int ** matrix, int A, int B)
{
	int ** visited = new int*[A+1];
	for(int i=0;i<=A;i++)
	{
		visited[i] = new int[B+1];
		memset(visited[i],0,sizeof(int)*B+1);
	}

	queue<pair<int,int> > pendingNodes;
	if(matrix[0][0]==1)return false;
	pendingNodes.push(make_pair(0,0));
	visited[0][0] = 1;
	while(!pendingNodes.empty())
	{
		pair<int,int> top = pendingNodes.front();
		pendingNodes.pop();
		int x = top.first;
		int y = top.second;
		if(x==A && y==B)return true;
		else{

			if(y+1<B && !matrix[x][y+1] && !visited[x][y+1])
			{
				visited[x][y+1] = 1;
				pendingNodes.push(make_pair(x,y+1));
			}

			if(x+1<A && !matrix[x+1][y] && !visited[x+1][y])
			{
				visited[x+1][y] = 1;
				pendingNodes.push(make_pair(x+1,y));	
			}

			if(x-1>0 && !matrix[x-1][y] && !visited[x-1][y])
			{
				visited[x-1][y] = 1;
				pendingNodes.push(make_pair(x-1,y));	
			}

			if(y-1>0 && !matrix[x][y-1] && !visited[x][y-1])
			{
				visited[x][y-1] = 1;
				pendingNodes.push(make_pair(x,y-1));	
			}

			if(x+1<A && y+1<B && !matrix[x+1][y+1] && !visited[x+1][y+1])
			{
				visited[x+1][y+1] = 1;
				pendingNodes.push(make_pair(x+1,y+1));	
			}

			if(x+1<A && y-1>0 && !matrix[x+1][y-1] && !visited[x+1][y-1])
			{
				visited[x+1][y-1] = 1;
				pendingNodes.push(make_pair(x+1,y-1));	
			}

			if(x-1>0 && y+1<B && !matrix[x-1][y+1] && !visited[x-1][y+1])
			{
				visited[x-1][y+1] = 1;
				pendingNodes.push(make_pair(x-1,y+1));	
			}

			if(x-1>0 && y-1>0 && !matrix[x-1][y-1] && !visited[x-1][y-1])
			{
				visited[x-1][y-1] = 1;
				pendingNodes.push(make_pair(x-1,y-1));	
			}
		}
	}
	return false;

	
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

	int ** matrix = new int*[A+1];
	for(int i=0;i<=A;i++)
	{
		matrix[i] = new int[B+1];
		memset(matrix[i],0,sizeof(int)*B+1);
	}

	queue<pair<int,int> > pendingNodes;
	for(int i=0;i<E.size();i++)
	{
		pendingNodes.push(make_pair(E[i],F[i]));
	}

	while(!pendingNodes.empty())
	{
		pair<int,int> top = pendingNodes.front();
		int x = top.first;
		int y = top.second;
		pendingNodes.pop();
		mark(matrix,A,B,x,y,D);
	}

	// for(int i=0;i<A;i++)
	// {
	// 	for(int j=0;j<B;j++)
	// 	{
	// 		cout<<matrix[i][j]<<" ";
	// 	}

	// 	cout<<endl;
	// }
	// cout<<"End"<<endl;

	bool ans = bfs(matrix,A,B);
	if(ans)return "YES";
	else return "NO";

	
}


int main()
{
	int A,B,C,D; 
	cin>>A>>B>>C>>D;
	vector<int> E(C); 
	vector<int> F(C);
	
	
	for(int i=0;i<C;i++)
	{
		cin>>E[i];
	}

	for(int i=0;i<C;i++)
	{
		cin>>F[i];
	}
	cout<<solve(A,B,C,D,E,F)<<endl;

}