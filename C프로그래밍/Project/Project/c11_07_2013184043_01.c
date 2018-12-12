#include<stdio.h>

int main(void)
{
	float a=0, b=0, c=0;
	printf("실수를 입력하시오 : ");
	if (scanf("%f", &a) != 1)
		return 0;
	printf("실수를 입력하시오 : ");
	if (scanf("%f", &b) != 1)
		return 0;
	printf("실수를 입력하시오 : ");
	if (scanf("%f", &c) != 1)
		return 0;

	printf("합계는 %f이고 평균값은 %f입니다.\n", a + b + c, (a + b + c) / 3.0f);

	return 0;
}