#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll; 

void mul(ll a[4][4],ll b[4][4]){
ll c[4][4];
for(int i=0;i<4;i++){
for(int j=0;j<4;j++){
c[i][j]=0;
for(int k=0;k<4;k++){
c[i][j]=(c[i][j]%MOD+((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
}
}
}

for(int i=0;i<4;i++){
for(int j=0;j<4;j++){
a[i][j]=c[i][j];
}
}
}

void find(ll a[4][4], ll n){
if(n==1) return ;
ll b[4][4]={{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,0,2}};	
find(a,n/2);
mul(a,a);
if(n&1) mul(a,b);
}


ll power(ll n){
if(n==1) return 2;
ll x;
x=power(n/2);
x=((x%MOD)*(x%MOD))%MOD;
if(n&1) x=((x%MOD)*2)%MOD;
return x;
}

int main(){
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
if(n==1) cout<<"2"<<endl;
else if(n==2) cout<<"4\n";
else if(n==3) cout<<"7\n";
else {
ll a[4][4]={{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,0,2}};	
find(a,n-3);
ll ans=(a[0][0]%MOD+((a[0][3]%MOD)*2)%MOD)%MOD;
//cout<<ans<<endl;
ans=(power(n)%MOD-ans%MOD+MOD)%MOD;
cout<<ans<<endl;
}

}
return 0;
}