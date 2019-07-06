#include<bits/stdc++.h>

using namespace std;

class Adder{
public:
	static int add(int a, int b){
		return a+b;
	}
};

int main()
{
	cout<<Adder().add(1,2)<<endl;
}