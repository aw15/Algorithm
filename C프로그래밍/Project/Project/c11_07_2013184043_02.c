#include<stdio.h>

int main(void)
{
	double mile = 0.0;
	printf("������ �Է��Ͻÿ� : ");
	if (scanf("%lf", &mile) != 1)
		return 0;
	printf("%lf������ %lf�����Դϴ�.\n", mile,mile*1609.0);

	return 0;
}