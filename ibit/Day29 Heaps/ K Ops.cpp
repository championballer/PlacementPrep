#include<bits/stdc++.h>

using namespace std;

class minheap{
	private:
		vector<vector<int> > arr;
	public:

		minheap(){
			vector<int> current;
			current.push_back(0);
			current.push_back(0);
			current.push_back(0);
			arr.push_back(current);
		}

		void insert(int index, int val, int cval){
			vector<int> current;
			current.push_back(index);
			current.push_back(val);
			current.push_back(cval);
			arr.push_back(current);
			upheapify();
		}

		vector<int> min(){
			if(arr.size()<=1)
				{
					vector<int> current;
					current.push_back(-1);
					current.push_back(INT_MAX);
					current.push_back(INT_MAX);
					return current;
				}
			return arr[1];
		}

		void del(){
			if(arr.size()<=1)return;
			vector<int> temp = arr.back();
			arr.back() = arr[1];
			arr[1] = temp;

			arr.pop_back();
			downheapify();
		}

	private:

		void swap(int i,int j)
		{
			vector<int> temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		void upheapify(){
			int i = arr.size()-1;
			while(i>1)
			{
				int p = i/2;
				if(arr[p][2]>arr[i][2])
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
				int val = arr[i][2];
				int c1 = 2*i,val1 = INT_MAX;
				int c2 = (2*i)+1,val2 = INT_MAX;
				if(c1<n)val1 = arr[c1][2];
				if(c2<n)val2 = arr[c2][2];

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

int main()
{
	minheap heap;
	heap.insert(0,3,3);
	cout<<heap.min()[2]<<endl;
	vector<int> mn = heap.min();
	heap.del();
	mn[2]+=mn[1];
	heap.insert(mn[0],mn[1],mn[2]);
	cout<<heap.min()[2]<<endl;
}
