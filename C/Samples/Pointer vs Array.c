#include<stdio.h>

int main()
{
	int arr [] = {1,2,3};
	int * ptr = arr;
	printf("%p\n",arr);
	printf("%p\n",&arr);
	printf("%p\n",&ptr);
	printf("%p\n",ptr);
	printf("%d\n",*ptr);
	printf("%d\n",*arr);
}