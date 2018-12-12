#include<stdio.h>

int main(void)
{
	int input = 0;
	printf("16진수 정수를 입력하시오 : ");
	if (scanf("%x", &input) == 1)
	{
		printf("8진수로는 0%o입니다.\n", input);
		printf("10진수로는 %d입니다.\n", input);
		printf("16진수로는 0x%x입니다.\n", input);
	}
	return 0;
}