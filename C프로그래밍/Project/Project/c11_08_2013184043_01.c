#include<stdio.h>

int main(void)
{
	float input = 0.0f;
	printf("�Ǽ��� �Է��Ͻÿ� : ");
	if (scanf("%f", &input) == 1)
	{
		printf("�Ǽ��������δ� %f�Դϴ�.\n", input);
		printf("�����������δ� %e�Դϴ�.\n", input);
	}
	return 0;
}