#include<bits/stdc++.h>

using namespace std;

int main()
{
	string toConvert = "23";
	int n = stoi(toConvert);
	cout<<toConvert<<" "<<typeid(toConvert).name()<<" "<<n<<" "<<typeid(n).name()<<endl;
}