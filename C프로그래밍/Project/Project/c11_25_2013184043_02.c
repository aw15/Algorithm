#include<stdio.h>


double f_to_c(double f)
{
	return 5.0 / 9.0 *(f - 32.0);
}

int main()
{
	double num = 0;
	

	if (scanf("%lf", &num) != 1)
		return printf("Invalid Input\n");

	printf("½ç½Ã¿Âµµ : %lf\n", f_to_c(num));


}