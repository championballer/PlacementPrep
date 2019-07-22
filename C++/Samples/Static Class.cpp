#include<bits/stdc++.h>

using namespace std;

class Test{
	public:
	static int i;
	int j;
	
	Test()
	{
		i = 0;
		j = 0;
	}
};

int Test::i;
int main()
{
	cout<<sizeof(Test)<<endl;
	
	Test a;
	Test::i++;
	cout<<Test::i<<endl;
	Test b;
	cout<<Test::i<<endl;
	
}
