#include<stdio.h>

int main(void)
{
	int x = 10,y = 20;
	printf("�ٲٱ� �� x = %d, y = %d\n",x,y);
	int temp = x;
	x = y;
	y = temp;
	printf("�ٲ� �� x = %d, y = %d\n", x, y);

	return 0;
}