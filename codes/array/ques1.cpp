/*

Rearrange an array such that arr[i] = i
Given an array of elements of length N, ranging from 0 to N – 1. 
All elements may not be present in the array. If element is not present 
then there will be -1 present in the array. Rearrange the array such 
that A[i] = i and if i is not present, display -1 at that place.


Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

Correct Method : Iterate over the array, and for each index check whether it is at
correct position or not. If not then exchange and then check for that element 
-> O(n) 

Method 1: Store all elements in a map -> O(n), then search for the index in the map, 
if present then place in the array, else place -1 -> O(n). 
Net -> O(n), space complexity -> O(n)

Method 2: Sort array and apply binary search for all indices -> O(nlogn)

Method 3: Linear Search for each element -> O(n*n)

*/

#include<bits/stdc++.h>

using namespace std;

int* rearrange(int * in, int size)
{
	int * out = new int[size];
	memset(out,-1,sizeof(int)*size);
	for(int i=0;i<size;i++)
	{
		if(in[i]!=-1)
		{
			out[in[i]] = in[i];
		}
		else continue;
	}

	return out;
}

int main()
{
	int size;
	cin>>size;

	int * in = new int[size];

	for(int i=0;i<size;i++)
	{
		cin>>in[i];
	}

	int * out = new int[size];
	out = rearrange(in,size);
	for(int i=0;i<size;i++)
	{
		cout<<out[i]<<" ";
	}
	cout<<endl;
	return 0;
}
