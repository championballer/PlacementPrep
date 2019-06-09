#include<stdio.h>

int main()
{

	int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
	int (*ptr)[4];
	int **p = arr; //throws warning
	ptr = arr;
	
	printf("%d\n",ptr[1][2]);
	printf("%p\n",p);

}
