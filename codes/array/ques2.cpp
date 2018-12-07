/*
Rotate array of size n by d moves. 

Method : Reversal Algorithm -> O(n)

1. r(A),B = Ar,B
2. Ar,r(B) = Ar,Br
3. r(Ar,Br) = BA
*/

#include<bits/stdc++.h>
using namespace std;
#include"helper.h"

void rev(int * arr, int n)
{
	for(int i=0,j=n-1;i<j;i++,j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int main()
{
	int size;
	cin>>size;

	int * arr = new int[size];
	memset(arr,0,sizeof(int)*size);
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	int d;
	cin>>d;

	rev(arr,d);
	rev(arr+d,size-d);
	rev(arr,size);

	print_array(arr,size);


}