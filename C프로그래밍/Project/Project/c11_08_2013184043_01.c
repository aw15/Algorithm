#include<stdio.h>

int main(void)
{
	float input = 0.0f;
	printf("실수를 입력하시오 : ");
	if (scanf("%f", &input) == 1)
	{
		printf("실수형식으로는 %f입니다.\n", input);
		printf("지수형식으로는 %e입니다.\n", input);
	}
	return 0;
}