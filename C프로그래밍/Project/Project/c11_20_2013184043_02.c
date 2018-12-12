#include<stdio.h>




int main(void)
{

	int number = 0;
	int sum = 0;
	int ret = 0;

	while (ret = scanf("%d", &number)!=EOF)
	{
		if (ret != 1)
		{
			printf("invalid input\n");
			break;
		}
		sum += number;
	} 

	printf("sum  = %d\n", sum);
}