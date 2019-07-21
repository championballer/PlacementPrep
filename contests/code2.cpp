#include<bits/stdc++.h>
using namespace std;

int prefix[100001];
bool vowel[100001];
bool checkVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
    else return false;
}

int CountRotations (string S, int N) {
   // Write your code here
  int result = 0;
  int mid = N/2;
  for(int i=1;i<=N;i++)
  {
      int l = i, r = i+mid-1;
      int raux = r%N;
      int c1 = 0;
      
      if(r>N)
      {
          r = N;
          c1 = prefix[r] - prefix[l-1];
          c1 += (prefix[raux] - prefix[0]);
      }
       
      else c1 = prefix[r] - prefix[l-1];
      //cout<<"c1 "<<l<<" "<<r<<" "<<raux<<" "<<c1<<endl; 
      
      l = (i+mid)%N;
      r = l+mid-1;
      raux = r%N;
      
      int c2 = 0;
       
      if(r>N)
      {
          r = N;
          c2 = prefix[r] - prefix[l-1];
          c2 += prefix[raux] - prefix[0];
      }
       
      else c2 = prefix[r] - prefix[l-1];
      //cout<<"c2 "<<l<<" "<<r<<" "<<raux<<" "<<c2<<endl;
      if(c1>c2)result++;
  }
   
  return result;
   
}

void compute(int N)
{
    prefix[0] = 0;
    for(int i=1;i<=N;i++)prefix[i] = prefix[i-1]+vowel[i];
    return;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        string S;
        cin>>S;
        memset(vowel,0,sizeof(bool)*(N+1));
        vowel[0] = 0;
        for(int i=0;i<N;i++)
        {
            if(checkVowel(S[i]))vowel[i+1] = 1;
            else vowel[i+1]=0;
        }
        memset(prefix,0,sizeof(int)*(N+1));
        compute(N);
        int out_;
        out_ = CountRotations(S, N);
        cout << out_;
        cout << "\n";
    }
}
