#include<bits/stdc++.h>
#include<math.h>

using namespace std;

#include<math.h>

class minheap{
	private:
		vector<pair<pair<int,int>,int> > arr;
	public:

		minheap(){
		    pair<pair<int,int>,float> p1;
		    p1.first.first = 0;
		    p1.first.second = 0;
		    p1.second = 0;
			arr.push_back(p1);
		}

		void insert(int x,int y){
		    float d = dis(x,y);
		    pair<pair<int,int>, float> p1;
		    p1.second = d;
		    p1.first.first = x;
		    p1.first.second = y;
			arr.push_back(p1);
			upheapify();
		}

		pair<pair<int,int>,float> min(){
			if(arr.size()<=1)return make_pair(make_pair(0,0),0) ;
			return arr[1];
		}

		void del(){
			if(arr.size()<=1)return;
			pair<pair<int,int>,float> temp = arr.back();
			arr.back() = arr[1];
			arr[1] = temp;

			arr.pop_back();
			downheapify();
		}

	private:

        int dis(int x,int y)
        {
            return sqrt(x*x+y*y);
        }
        
		void swap(int i,int j)
		{
			pair<pair<int,int>,float> temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		void upheapify(){
			int i = arr.size()-1;
			while(i>1)
			{
				int p = i/2;
				if(arr[p].second>arr[i].second)
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
				int val = arr[i].second;
				int c1 = 2*i,val1 = INT_MAX;
				int c2 = (2*i)+1,val2 = INT_MAX;
				if(c1<n)val1 = arr[c1].second;
				if(c2<n)val2 = arr[c2].second;

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



vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    
    vector<vector<int> > result;
    minheap heap;
    for(int i=0;i<A.size();i++)
    {
        heap.insert(A[i][0],A[i][1]);
    }
    
    for(int i=0;i<B;i++)
    {
        pair<pair<int,int>,float> mn = heap.min();
        heap.del();
        vector<int> current;
        current.push_back(mn.first.first);
        current.push_back(mn.first.second);
        result.push_back(current);
    }
    return result;
    
}

int main()
{
	minheap heap;

	heap.insert(1,2);
	cout<<heap.min().second<<endl;
	heap.insert(0,1);
	cout<<heap.min().second<<endl;
	heap.del();
	cout<<heap.min().second<<endl;
}
