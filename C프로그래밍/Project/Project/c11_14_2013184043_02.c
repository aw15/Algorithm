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
		printf("����Դϴ�.\n");
	else
		printf("����� �ƴմϴ�.\n");

	return 0;
}