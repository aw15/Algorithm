#include<stdio.h>

int main(void)
{
	double x=0.0, y=0.0, z = 0.0;
	printf("������ ����, ����, ���̸� �ѹ��� �Է� : ");
	if (scanf("%lf %lf %lf", &x,&y,&z) == 3)
	{
		printf("������ ���Ǵ� %lf�Դϴ�.\n", x*y*z);
	}
	return 0;
}