#include<stdio.h>


int main(void)
{
	double x = 0., y = 0.;
	printf("2개의 실수를 입력하시오 : ");
	if (scanf("%lf %lf", &x, &y) == 2)
	{
		if (y != 0)
		{
			printf("%lf\t%lf\t%lf\t%lf", x+y,x-y,x*y,x/y);
		}
	}
	return 0;
}