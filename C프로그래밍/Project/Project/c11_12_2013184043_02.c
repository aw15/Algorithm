#include<stdio.h>


int main(void)
{
	double x = 0., y = 0.;
	printf("2���� �Ǽ��� �Է��Ͻÿ� : ");
	if (scanf("%lf %lf", &x, &y) == 2)
	{
		if (y != 0)
		{
			printf("%lf\t%lf\t%lf\t%lf", x+y,x-y,x*y,x/y);
		}
	}
	return 0;
}