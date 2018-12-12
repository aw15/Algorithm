#include<stdio.h>


double cal_area(double rad)
{
	return rad * rad*3.141592;
}

int main()
{
	double num = 0;


	if (scanf("%lf", &num) != 1)
		return printf("Invalid Input\n");

	printf("원의 면적 : %lf\n", cal_area(num));
}