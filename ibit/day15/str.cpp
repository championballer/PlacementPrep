#include<bits/stdc++.h>

using namespace std;

void preprocess(string& A){
    
    int first = 0;
    int last = A.length()-1;
    cout<<last<<endl;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='_')first++;
        else break;
    }
    
    for(int i=A.length()-1;i>=0;i--)
    {
        if(A[i]=='_')last--;
        else break;
    }
    cout<<last<<endl;
    A = A.substr(first,last-first+1);
}


int main()
{
	string A = "____abcdge___";
	cout<<A<<endl;
	//string B = A.substr(2,A.length());
	preprocess(A);
	cout<<A<<endl;

	string B = "______abchedrjehs";
	cout<<B<<endl;
	preprocess(B);
	cout<<B<<endl;
}