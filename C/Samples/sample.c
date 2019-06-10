#include<stdio.h>

int main()
{
	char * ptr = "geeksforgeeks";
	printf("%p\n",*&*&ptr);
	printf("%c\n",*&*&ptr);
}