#include<stdio.h>


int main(void)
{
	int x = 0, y = 0;
	printf("2개의 정수를 입력하시오 : ");
	if (scanf("%d %d", &x, &y) == 2)
	{
		if (y != 0)
		{
			printf("몫 = %d   나머지 = %d", x / y, x%y);
		}
	}
	return 0;
}