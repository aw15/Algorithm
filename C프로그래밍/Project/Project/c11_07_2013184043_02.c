#include<stdio.h>

int main(void)
{
	double mile = 0.0;
	printf("마일을 입력하시오 : ");
	if (scanf("%lf", &mile) != 1)
		return 0;
	printf("%lf마일은 %lf미터입니다.\n", mile,mile*1609.0);

	return 0;
}