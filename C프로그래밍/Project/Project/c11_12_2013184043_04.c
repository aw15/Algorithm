#include<stdio.h>


int main(void)
{
	int height = 0;
	printf("Ű�� �Է��Ͻÿ� : ");
	if (scanf("%d", &height) == 1)
	{
		float inch = height / 2.54;
		int feet = (int)inch / 12;
		printf("%dcm��  :  %d��Ʈ %f��ġ�Դϴ�.", height,feet,inch - 12*feet);
	}
	return 0;
}