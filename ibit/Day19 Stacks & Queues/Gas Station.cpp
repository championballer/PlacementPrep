#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuit(const vector<int> &A,const vector<int> &B) {
    
    int current_fuel = 0;
    
    for(int i=0;i<A.size();)
    {
        int current = i;
        current_fuel+=A[current];
        current_fuel-=B[current];
        //cout<<current<<" "<<A[current]<<" "<<B[current]<<" "<<current_fuel<<endl;
        while(current_fuel>0)
        {
            current=(current+1)%A.size();
            if(i==current)return i;
            
            current_fuel+=A[current];
            current_fuel-=B[current];

            //cout<<current<<" "<<A[current]<<" "<<B[current]<<" "<<current_fuel<<endl;
        }
        if(current_fuel<0)
        {
            if(current>=0 && current<i)return -1;
            else
            {
                i=current+1;
                current_fuel=0;
            }
        }
    }
    
    return -1;
}

/* 
959 329 987 951 942 410 282 376 581 507 546 299 564 114 474 163 953 481 337 395 679 21 335 846 878 961 663 413 610 937 32 831 239 899 659 718 738 7 209 
862 783 134 441 177 416 329 43 997 920 289 117 573 672 574 797 512 887 571 657 420 686 411 817 185 326 891 122 496 905 910 810 226 462 759 637 517 237 884 
*/
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }

    cout<<canCompleteCircuit(A,B)<<endl;
}
