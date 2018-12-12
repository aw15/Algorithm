#include<stdio.h>


int main(void)
{
	int a, b;
	printf("input two number : ");
	int retval = scanf("%d %d", &a,&b);
	if (retval != 2||b==0)
	{
		printf("invalid input\n");
		return -1;
	}
	
	if (a%b == 0)
		printf("약수입니다.\n");
	else
		printf("약수가 아닙니다.\n");

	return 0;
}