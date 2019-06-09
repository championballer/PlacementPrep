/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
}  

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()==0 || A.size()==1)return A;
    sort(A.begin(),A.end(),compareInterval);
    vector<Interval> result;
    Interval k1 = A[0];
    Interval k2 = A[1];
    stack<Interval> buffer;
    if(max(k1.start,k2.start)<=min(k1.end,k2.end))
    {
        Interval to_push;
        to_push.start = min(k1.start,k2.start);
        to_push.end = max(k1.end,k2.end);
        
        buffer.push(to_push);
    }
    
    else
    {
        buffer.push(k1);
        buffer.push(k2);
    }
    
    for(int i=2;i<A.size();i++)
    {   
        Interval k1 = buffer.top();
        Interval k2 = A[i];
        buffer.pop();
        
        if(max(k1.start,k2.start)<=min(k1.end,k2.end))
        {
            Interval to_push;
            to_push.start = min(k1.start,k2.start);
            to_push.end = max(k1.end,k2.end);
        
            buffer.push(to_push);
        }
    
        else
        {
            buffer.push(k1);
            buffer.push(k2);
        }
    }
    
    while(!buffer.empty())
    {
        result.push_back(buffer.top());
        buffer.pop();
    }
    
    reverse(result.begin(),result.end()); 
    return result;
}
