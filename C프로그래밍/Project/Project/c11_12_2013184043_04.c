#include<stdio.h>


int main(void)
{
	int height = 0;
	printf("키를 입력하시오 : ");
	if (scanf("%d", &height) == 1)
	{
		float inch = height / 2.54;
		int feet = (int)inch / 12;
		printf("%dcm는  :  %d피트 %f인치입니다.", height,feet,inch - 12*feet);
	}
	return 0;
}