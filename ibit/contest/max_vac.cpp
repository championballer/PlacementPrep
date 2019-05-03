#include<bits/stdc++.h>

using namespace std;

bool compare(pair<pair<int,int>,int > i1,pair<pair<int,int>,int> i2)
{
    return i1.first.first<i2.first.first;
}

vector<int> solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F) {
    
    vector<int> result;
    vector<pair<pair<int,int>,int> > dates;
    
    //Filter process
    for(int i=0;i<A;i++)
    {
        if(D[i]>=B && E[i]<=C)
        {
            dates.push_back(make_pair(make_pair(D[i],E[i]),F[i]));
        }
    }
    
    /*for(int i=0;i<dates.size();i++)
    {
        cout<<dates[i].first.first<<" "<<dates[i].first.second<<endl;
    }
    cout<<endl;*/


    //Sorting array as per the starting date
    sort(dates.begin(),dates.end(),compare);
    
    /*for(int i=0;i<dates.size();i++)
    {
        cout<<dates[i].first.first<<" "<<dates[i].first.second<<endl;
    }
    cout<<endl;*/
    
    int max_sum = -1;
    int min_cost = INT_MAX;
    for(int i=0;i<dates.size();i++)
    {
        int sum = dates[i].first.second-dates[i].first.first;
        int cost = dates[i].second;
        for(int j=i;j<dates.size();j++)
        {
            if(dates[j].first.first>dates[i].first.second)
            {
                sum+=dates[j].first.second-dates[j].first.first;
                cost+=dates[j].second;
            }

            if(sum>max_sum)max_sum = sum;
            if(cost<min_cost)min_cost= cost;
        }
    }

    result.push_back(max_sum);
    if(min_cost==INT_MAX)min_cost = -1;
    result.push_back(min_cost);
    return result;
}

int main()
{
    int A,B,C;
    cin>>A>>B>>C;

    vector<int> D;
    vector<int> E;
    vector<int> F;
    for(int i=0;i<A;i++)
    {
        int f,s,t;
        cin>>f>>s>>t;
        D.push_back(f);
        E.push_back(s);
        F.push_back(t);
    }

    vector<int> result = solve(A,B,C,D,E,F);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
}
