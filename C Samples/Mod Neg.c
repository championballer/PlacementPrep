#include<stdio.h>

int main()
{
	int a = -11;
	int b = 8;
	int c = a%b;
	int d = (a%b+b)%b;
	printf("%d\n",c);
	printf("%d\n",d);

	int e = -4;
	int f = 11;
	int g = f%e;
	printf("%d\n",g);
}