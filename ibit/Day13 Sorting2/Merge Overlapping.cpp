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
    if(max(i1.start,i2.start)<=min(i1.end,i2.end))return true;
    else return false;
}

Interval mergeInterval(Interval i1, Interval i2)
{
    Interval i3;
    i3.start = min(i1.start,i2.start);
    i3.end = max(i1.end, i2.end);
    return i3;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()==0 || A.size()==1)return A;
    sort(A.begin(),A.end(),sortInterval);
    stack<Interval> st;
    for(int i=A.size()-1;i>=0;i--)
    {
        st.push(A[i]);
        A.pop_back();
    }
    
    while(!st.empty())
    {
        Interval i1 = st.top();st.pop();
        Interval i2 = st.top();st.pop();
        
        if(checkOverlap(i1,i2))
        {
            Interval i3 = mergeInterval(i1,i2);
            if(st.empty())A.push_back(i3);
            else
            {
                st.push(i3);
            }
        }
        
        else
        {
            if(st.empty())
            {
                A.push_back(i1);
                A.push_back(i2);
            }
            
            else
            {
                A.push_back(i1);
                st.push(i2);
            }
            
        }
    }
    
    sort(A.begin(),A.end(),sortInterval);
    return A;
}
