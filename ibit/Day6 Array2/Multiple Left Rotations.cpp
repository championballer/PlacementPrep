void reverse(vector<int> & arr, int x, int y)
{
	for(int i=x,j=y;i<j;i++,j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void rotate(vector<int> & arr, int index)
{
	reverse(arr,0,index-1);
	reverse(arr,index,arr.size()-1);
	reverse(arr,0,arr.size()-1);
}


vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    
    vector<vector<int> > result;
    for(int i=0;i<B.size();i++)
    {
        
        int current = B[i]%A.size();
        vector<int> copy = A;
        rotate(copy,current);
        result.push_back(copy);
    }
    
    return result;
}
