#include<stdio.h>

int main(void)
{
	float a=0, b=0, c=0;
	printf("�Ǽ��� �Է��Ͻÿ� : ");
	if (scanf("%f", &a) != 1)
		return 0;
	printf("�Ǽ��� �Է��Ͻÿ� : ");
	if (scanf("%f", &b) != 1)
		return 0;
	printf("�Ǽ��� �Է��Ͻÿ� : ");
	if (scanf("%f", &c) != 1)
		return 0;

	printf("�հ�� %f�̰� ��հ��� %f�Դϴ�.\n", a + b + c, (a + b + c) / 3.0f);

	return 0;
}