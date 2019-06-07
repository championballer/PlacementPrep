#include<bits/stdc++.h>

using namespace std;

int pow(int x, int n, int d) {
    

    if(x==0)return 0;
    if(n==0)return 1;
 	if(n%2==0)
 	{
 		int x_2 = ((((long long)x%d)*(x%d))+d)%d;
 		return pow(x_2,n/2,d);
 	}   

 	else
 	{
 		int sans =  (((long long)x*pow(x,n-1,d))+d)%d;
 		return sans;
 	}

 }

int main()
{
	cout<<pow(79161127,99046373,57263970)<<endl;
}