#include<stdio.h>


int main(void)
{
	int num = 0;
	int ret = scanf("%d", &num);
	if (ret != 1)
	{
		printf("invalid input\n");
		return -1;
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
}