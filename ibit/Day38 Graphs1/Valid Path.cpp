#include<bits/stdc++.h>

using namespace std;

/*
41 67 5 0
17 16 12 0 40
52 61 61 25 31
*/

/*
40 51 3 9
27 1 16
2 45 7
*/
void mark(bool ** matrix, int A, int B,int x, int y, int dis, int R, bool ** visited)
{
	if(x<0 || x>A || y<0 || y>B)return;
	if(dis>R)return;
	if(visited[x][y])return;

	matrix[x][y] = 1;
	visited[x][y] = 1;
	mark(matrix,A,B,x+1,y,dis+1,R,visited);
	mark(matrix,A,B,x,y+1,dis+1,R,visited);
	mark(matrix,A,B,x+1,y+1,dis+1,R,visited);
	mark(matrix,A,B,x-1,y,dis+1,R,visited);
	mark(matrix,A,B,x,y-1,dis+1,R,visited);
	mark(matrix,A,B,x-1,y-1,dis+1,R,visited);
	mark(matrix,A,B,x+1,y-1,dis+1,R,visited);
	mark(matrix,A,B,x-1,y+1,dis+1,R,visited);
	visited[x][y] = 0;
}

bool travel(bool ** matrix, int A, int B,bool ** visited)
{
	queue<pair<int,int> > pendingNodes;
	pendingNodes.push(make_pair(0,0));

	while(!pendingNodes.empty())
	{
		pair<int,int> top = pendingNodes.front();
		pendingNodes.pop();

		int x = top.first;
		int y = top.second;

		if(x<0 || x>A || y<0 || y>B)continue;
		if(visited[x][y])continue;
		if(matrix[x][y])continue;
		if(x==A && y==B)return true;
		visited[x][y] = true;
		pendingNodes.push(make_pair(x+1,y));
		pendingNodes.push(make_pair(x,y+1));
		pendingNodes.push(make_pair(x+1,y+1));
		pendingNodes.push(make_pair(x-1,y));
		pendingNodes.push(make_pair(x,y-1));
		pendingNodes.push(make_pair(x-1,y-1));
		pendingNodes.push(make_pair(x+1,y-1));
		pendingNodes.push(make_pair(x-1,y+1));
	}

	return false;

}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

	bool ** matrix = new bool*[A+1];
	for(int i=0;i<=A;i++)
	{
		matrix[i] = new bool[B+1];
		memset(matrix[i],0,sizeof(bool)*(B+1));
	}

	queue<pair<int,int> > pendingNodes;
	for(int i=0;i<E.size();i++)
	{
		pendingNodes.push(make_pair(E[i],F[i]));
	}


	bool ** visited = new bool*[A+1];
	for(int i=0;i<=A;i++)visited[i] = new bool[B+1];

	while(!pendingNodes.empty())
	{
		pair<int,int> top = pendingNodes.front();
		int x = top.first;
		int y = top.second;
		pendingNodes.pop();
		mark(matrix,A,B,x,y,0,D,visited);
	}

	for(int i=0;i<=A;i++)
	{
		for(int j=0;j<=B;j++)
		{
			//if(matrix[i][j])
			cout<<matrix[i][j]<<" ";
		}

		cout<<endl;
	}
	cout<<"End"<<endl;
	bool ans = travel(matrix,A,B,visited);
	if(ans)return "YES";
	else return "NO";

	return "YES";	
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