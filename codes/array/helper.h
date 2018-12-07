void print_array(int * arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int pivot(int * in,int size)
{
	int left=0,right=size-1;

	if(in[left]<in[right])return -1;
	while(left<=right)
	{
		int mid = left+(right-left)/2;
		int midl = (mid-1)%size;
		int midr = (mid+1)%size;

		if(in[mid]>in[midl] && in[mid]>in[midr])return mid;
		else if(in[mid]<in[left] && in[mid]<in[right])
		{
			right = mid-1;
		}

		else left = mid+1;
	}
}