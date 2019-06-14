#include<bits/stdc++.h>

using namespace std;

int sq(int x){return x*x;}
void print(vector<vector<int> > & arg)
{
	for(int i=0;i<arg.size();i++)
	{
		for(int j=0;j<arg[i].size();j++)cout<<arg[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

// void mark(vector<vector<int> > & matrix, vector<vector<int> > & visited, int x, int y, int r, int dis)
// {
// 	//cout<<x<<" "<<y<<endl;
// 	int A = matrix.size();
// 	int B = matrix[0].size();
// 	if(dis>r)return;
// 	if(x<0 || x>=A || y<0 || y>=B)return;
// 	if(visited[x][y])return;
// 	//cout<<x<<" "<<y<<endl;
// 	visited[x][y] = 1;
// 	matrix[x][y] = 0;
// 	mark(matrix,visited,x+1,y,r,dis+1);
// 	mark(matrix,visited,x,y+1,r,dis+1);
// 	mark(matrix,visited,x+1,y+1,r,dis+1);
// 	mark(matrix,visited,x-1,y,r,dis+1);
// 	mark(matrix,visited,x,y-1,r,dis+1);
// 	mark(matrix,visited,x-1,y-1,r,dis+1);
// 	mark(matrix,visited,x+1,y-1,r,dis+1);
// 	mark(matrix,visited,x-1,y+1,r,dis+1); 
// 	visited[x][y] = 0;
// }
bool isSafe(int x, int y, vector<int> & E, vector<int> & F, int D)
{
	for(int i=0;i<E.size();i++)	
	{
		int px = E[i];
		int py = F[i];

		if(sq(px-x)+sq(py-y)<=sq(D))return false;
	}

	return true;
}

bool validPath(vector<vector<int> > & visited, int x, int y,vector<int> & E, vector<int> & F, int D)
{
	cout<<x<<" "<<y<<endl;
	int A = visited.size();
	int B = visited[0].size();
	if(x<0 || x>=A || y<0 || y>=B)return 0;
	if(visited[x][y])return false;
	if(!isSafe(x,y,E,F,D))
	{
		visited[x][y] = 1;
		return false;
	}
	if(x==A-1 && y==B-1)return isSafe(x,y,E,F,D);

	visited[x][y] = 1;
	int tx[8] = {1,0,1,-1,-1,-1,0,1};
	int ty[8] = {0,1,1,1,0,-1,-1,-1};
	for(int i=0;i<8;i++)
	{

		bool sans = validPath(visited,x+tx[i],y+ty[i],E,F,D);
		if(sans)
		{
			return sans;
		}
	}
	return false;
}


string solve(int A, int B, int C, int D, vector<int> & E, vector<int> & F)
{
	vector<vector<int> > visited(A+1,vector<int>(B+1,0));

	bool ans = validPath(visited,0,0,E,F,D);
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
