#include<stdio.h>


int main(void)
{
	int x = 0, y = 0, z = 0;
	printf("3���� ������ �Է��Ͻÿ� : ");
	if (scanf("%d %d %d", &x, &y,&z) == 3)
	{
		int max = x > y ? (x > z ? x : z) : (y > z ? y : z);
		printf(" �ִ밪 :  %d",max );
	}
	return 0;
}