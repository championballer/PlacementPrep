#include<stdio.h>

void add(int a, int b)
{
	printf("%d\n",a+b);
}

void subtract(int a, int b)
{
	printf("%d\n",a-b);
}

void multiply(int a, int b)
{
	printf("%d\n",a*b);
}

int main()
{
	void (*fun_ptr_arr[])(int,int) = {add,subtract,multiply};

	fun_ptr_arr[0](10,10);
}