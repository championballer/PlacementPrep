class minheap{
	private:
		vector<int> arr;
	public:

		minheap(){
			arr.push_back(0);
		}

		void insert(int k){
			arr.push_back(k);
			upheapify();
		}

		int min(){
			if(arr.size()<=1)return INT_MAX;
			return arr[1];
		}

		void del(){
			if(arr.size()<=1)return;
			int temp = arr.back();
			arr.back() = arr[1];
			arr[1] = temp;

			arr.pop_back();
			downheapify();
		}

	private:

		void swap(int i,int j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		void upheapify(){
			int i = arr.size()-1;
			while(i>1)
			{
				int p = i/2;
				if(arr[p]>arr[i])
				{
					swap(i,p);
					i/=2;
				}

				else break;
			}
		}

		void downheapify(){
			int i = 1, n = arr.size();

			while(i<n)
			{
				int val = arr[i];
				int c1 = 2*i,val1 = INT_MAX;
				int c2 = (2*i)+1,val2 = INT_MAX;
				if(c1<n)val1 = arr[c1];
				if(c2<n)val2 = arr[c2];

				if(val>val1 && val>val2)
				{
					if(val1<val2)
					{
						swap(i,c1);
						i = c1;
					}

					else
					{
						swap(i,c2);
						i = c2;
					}
				}

				else if(val>val1)
				{
					swap(i,c1);
					i=c1;
				}

				else if(val>val2)
				{
					swap(i,c2);
					i=c2;
				}

				else
				{
					break;
				}

			}
		}
};

class maxheap{
	private:
		vector<int> arr;
	public:

		maxheap(){
			arr.push_back(0);
		}

		void insert(int k){
			arr.push_back(k);
			upheapify();
		}

		int max(){
			if(arr.size()<=1)return INT_MAX;
			return arr[1];
		}

		void del(){
			if(arr.size()<=1)return;
			int temp = arr.back();
			arr.back() = arr[1];
			arr[1] = temp;

			arr.pop_back();
			downheapify();
		}

	private:

		void swap(int i,int j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		void upheapify(){
			int i = arr.size()-1;
			while(i>1)
			{
				int p = i/2;
				if(arr[p]<arr[i])
				{
					swap(i,p);
					i/=2;
				}

				else break;
			}
		}

		void downheapify(){
			int i = 1, n = arr.size();

			while(i<n)
			{
				int val = arr[i];
				int c1 = 2*i,val1 = INT_MIN;
				int c2 = (2*i)+1,val2 = INT_MIN;
				if(c1<n)val1 = arr[c1];
				if(c2<n)val2 = arr[c2];

				if(val<val1 && val<val2)
				{
					if(val1>val2)
					{
						swap(i,c1);
						i = c1;
					}

					else
					{
						swap(i,c2);
						i = c2;
					}
				}

				else if(val<val1)
				{
					swap(i,c1);
					i=c1;
				}

				else if(val<val2)
				{
					swap(i,c2);
					i=c2;
				}

				else
				{
					break;
				}

			}
		}
};

vector<int> Solution::solve(int A, int B, vector<int> &C) {
    
    minheap heapmin;
    maxheap heapmax;
    for(int i=0;i<B;i++)
    {
        heapmin.insert(C[i]);
        heapmax.insert(C[i]);
    }
    
    int mn = 0, mx = 0;
    for(int i=0;i<A;i++)
    {
        int current=heapmin.min();
        mn+=current;
        heapmin.del();
        if(current-1!=0)heapmin.insert(current-1);
        
        current = heapmax.max();
        mx+=current;
        heapmax.del();
        if(current-1!=0)heapmax.insert(current-1);
    }
    
    vector<int> ans;
    ans.push_back(mx);
    ans.push_back(mn);
    
    return ans;
}
