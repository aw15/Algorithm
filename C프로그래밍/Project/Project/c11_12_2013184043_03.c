#include<stdio.h>


int main(void)
{
	int x = 0, y = 0, z = 0;
	printf("3개의 정수를 입력하시오 : ");
	if (scanf("%d %d %d", &x, &y,&z) == 3)
	{
		int max = x > y ? (x > z ? x : z) : (y > z ? y : z);
		printf(" 최대값 :  %d",max );
	}
	return 0;
}