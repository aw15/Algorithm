#include<stdio.h>


int main(void)
{
	int x = 0, y = 0;
	printf("2���� ������ �Է��Ͻÿ� : ");
	if (scanf("%d %d", &x, &y) == 2)
	{
		if (y != 0)
		{
			printf("�� = %d   ������ = %d", x / y, x%y);
		}
	}
	return 0;
}