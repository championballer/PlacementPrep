#include<bits/stdc++.h>

using namespace std;

// class myComparator 
// { 
// public: 
//     int operator() (const pair<int,int> & p1, const pair<int,int> & p2) 
//     { 
//         return p1.first > p2.first; 
//     } 
// };

int compare(pair<int,int> p1,pair<int,int> p2)
{
	return p1.first>p2.first;
} 

int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

	pq.push(make_pair(2,3));
	cout<<pq.top().first<<" "<<pq.top().second<<endl;
	pq.push(make_pair(5,4));
	cout<<pq.top().first<<" "<<pq.top().second<<endl;
	pq.push(make_pair(1,4));
	cout<<pq.top().first<<" "<<pq.top().second<<endl;
	pq.push(make_pair(1,2));
	cout<<pq.top().first<<" "<<pq.top().second<<endl;


}