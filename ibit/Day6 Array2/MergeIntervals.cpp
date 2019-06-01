/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool sortInterval(Interval i1,Interval i2)
{
    return i1.start<i2.start;
}

 
bool checkOverlap(Interval i1, Interval i2)
{
    if(max(i1.start,i2.start)<min(i1.end,i2.end))return true;
    else return false;
    
}

Interval merge(Interval i1, Interval i2)
{
    Interval i3;
    i3.start = min(i1.start,i2.start);
    i3.end = max(i1.end,i2.end);
    
    return i3;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(intervals.size()==0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    if(newInterval.start>newInterval.end)
    {
        int temp = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = temp;
    }
    stack<Interval> st;
    for(int i=intervals.size()-1;i>=0;i--)
    {
        st.push(intervals[i]);
        intervals.pop_back();
    }
    
    st.push(newInterval);
    
    while(!st.empty())
    {
        Interval i1 = st.top();st.pop();
        Interval i2 = st.top();st.pop();
        //cout<<"i1:"<<i1.start<<" "<<i1.end<<endl;
        //cout<<"i2:"<<i2.start<<" "<<i2.end<<endl;
        if(checkOverlap(i1,i2))
        {
            Interval i3 = merge(i1,i2);
            if(st.empty())intervals.push_back(i3);
            else st.push(i3);
        }
        
        else
        {
            if(st.empty())
            {
                if(i1.start<i2.start)
                {
                    intervals.push_back(i1);
                    intervals.push_back(i2);
                }
                
                else
                {
                    intervals.push_back(i2);
                    intervals.push_back(i1);
                }
            }
            
            else
            {
                intervals.push_back(i2);
                st.push(i1);
            }
        }
    }
    
    sort(intervals.begin(),intervals.end(),sortInterval);
    return intervals;
}

