#include<stdio.h>
#include<math.h>

//- �ذ� ���ų�, 1���̰ų�, 2���̰ų� ����� ��� �� �ٿ� ����Ѵ�.
//- 3���� ���ڰ� �Էµ��� ���� ���(�����̰ų� EOF �� ������) ������ �޽����� ����ϰ� �����Ѵ�
//- a = 0, b = 0, c = 0 �� ��츦 ó���Ѵ�
//- a = 0, b = 0, c<>0 �� ��츦 ó���Ѵ�
//- a = 0, b<>0 �� ��츦 ó���Ѵ�.
//- �Ǻ����� + �� ��츦 ó���Ѵ�
//- �Ǻ����� - �� ��츦 ó���Ѵ�
//- �Ǻ����� 0 �� ��츦 ó���Ѵ�
int main(void)
{
	double a, b, c;
	if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		if (a == 0)
		{
			if (b == 0)
			{
				if(c==0)
					printf("All number\n");
				else 
					printf("No Answer");
			}
			else
			{
				printf("Linear %lf", c/b);
			}
		}
		else
		{
			double dis = (b*b) - (4*a*c);
			if (dis > 0)
			{
				printf("Two Answer : ");
			}
			if (dis == 0)
			{
				printf("One Answer : ");
			}
			if (dis < 0)
			{
				printf("No real root Answer : ");
			}
		}
	}
	else
	{
		printf("Input Error\n");
		return 0;
	}
	
}