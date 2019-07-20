#include<bits/stdc++.h>

void rev(string & a)
{
    for(int i=0,j=a.length()-1;i<=j;i++,j--)
    {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    bitset<32> s(A);
    string h = s.to_string();
    rev(h);
    bitset<32> ansset(h);
    int ans = ansset.to_ulong();
    return ans;
}

