#include<stdio.h>

int main(void)
{
	int input = 0;
	printf("16���� ������ �Է��Ͻÿ� : ");
	if (scanf("%x", &input) == 1)
	{
		printf("8�����δ� 0%o�Դϴ�.\n", input);
		printf("10�����δ� %d�Դϴ�.\n", input);
		printf("16�����δ� 0x%x�Դϴ�.\n", input);
	}
	return 0;
}