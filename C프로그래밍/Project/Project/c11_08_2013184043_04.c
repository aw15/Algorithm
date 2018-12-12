#include<stdio.h>

int main(void)
{
	double x=0.0, y=0.0, z = 0.0;
	printf("상자의 가로, 세로, 높이를 한번에 입력 : ");
	if (scanf("%lf %lf %lf", &x,&y,&z) == 3)
	{
		printf("상자의 부피는 %lf입니다.\n", x*y*z);
	}
	return 0;
}