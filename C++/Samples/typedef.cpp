#include<bits/stdc++.h>

using namespace std;

int main()
{
	int * x, y;
	cout<<sizeof x<<" "<<sizeof y<<endl;
	
	x = &y;
	y = 2;
	cout<<x<<" "<<y<<endl;
}
