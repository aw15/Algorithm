#include<stdio.h>

int main(void)
{
	int x = 10,y = 20;
	printf("바꾸기 전 x = %d, y = %d\n",x,y);
	int temp = x;
	x = y;
	y = temp;
	printf("바꾼 후 x = %d, y = %d\n", x, y);

	return 0;
}