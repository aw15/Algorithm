#include<stdio.h>


int main(void)
{
	int a, b, c;
	printf("input three number : ");
	int retval = scanf("%d %d %d", &a, &b, &c);
	if (retval != 3)
	{
		printf("invalid input\n");
		return -1;
	}
	int min;
	if (a < b)
	{
		if (a < c)
		{
			min = a;
		}
		else
		{
			min = c;
		}
	}
	else
	{
		if (b < c)
		{
			min = b;
		}
		else
		{
			min = c;
		}
	}
	printf("���� ���� ������ %d �Դϴ�.", min);

	return 0;

}