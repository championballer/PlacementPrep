#include<bits/stdc++.h>

using namespace std;

void reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string result = "";
    vector<string> corpus;
    string current = "";
    for(int i=0;i<A.length();)
    {
        current="";
        while(A[i]!=' ' && i<A.length())
        {
            current+=A[i];
            i++;
        }
        
        if(current!="")corpus.push_back(current);
        i++;
    }
    
    for(int i=0;i<corpus.size();i++)cout<<corpus[i]<<endl;
    
    for(int i=corpus.size()-1;i>=0;i--)
    {
        result+=corpus[i];
        if(i==0)continue;
        result+=' ';
    }
    
    A = result;
}

int main()
{
    string A = "fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
    reverseWords(A);
    cout<<A<<endl;
}
