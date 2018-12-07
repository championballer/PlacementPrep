/*Search an element in a sorted and rotated array
An element in a sorted array can be found in O(log n) time via binary search. 
But suppose we rotate an ascending order sorted array at some pivot unknown 
to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
Devise a way to find an element in the rotated array in O(log n) time.

Method : Find pivot index and accordingly call binary search on left or right
part of the array
*/

#include<bits/stdc++.h>
using namespace std;

int pivot(int * in,int size)
{
	int left=0,right=size-1;

	if(in[left]<in[right])return -1;
	while(left<=right)
	{
		int mid = left+(right-left)/2;
		int midl = (mid-1+size)%size;
		int midr = (mid+1)%size;

		if(in[mid]>in[midl] && in[mid]>in[midr])return mid;
		else if(in[mid]<in[left] && in[mid]<in[right])
		{
			right = mid-1;
		}

		else left = mid+1;
	}
}

int binary_search(int* in, int left,int right, int element_to_search)
{
	
	while(left<=right)
	{
		int mid = left+(right-left)/2;

		if(in[mid]==element_to_search)
		{
			return mid;
		}

		else if(in[mid]>element_to_search)
		{
			right = mid-1;
		}

		else left = mid+1;
	}

	return -1;
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

	int index = pivot(in,size);
	cout<<index<<endl;
	int element_to_search;
	cin>>element_to_search;

	if(index!=-1)
	{
		int ll = 0,lr = index;
		int rl = index+1, rr = size-1;

		if(in[ll]<=element_to_search && in[lr]>=element_to_search)
		{
			cout<<binary_search(in,ll,lr,element_to_search)<<endl;
		}

		else if(in[rl]<=element_to_search && in[rr]>=element_to_search)
		{
			cout<<binary_search(in,rl,rr,element_to_search)<<endl;
		}

		else cout<<-1<<endl;	
	}
	
	else
	{
		cout<<binary_search(in,0,size-1,element_to_search)<<endl;
	}
}