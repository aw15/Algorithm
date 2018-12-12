#include<stdio.h>
#include<math.h>

//- 해가 없거나, 1개이거나, 2개이거나 결과는 모두 한 줄에 출력한다.
//- 3개의 숫자가 입력되지 않을 경우(문자이거나 EOF 를 만나면) 적절한 메시지를 출력하고 종료한다
//- a = 0, b = 0, c = 0 일 경우를 처리한다
//- a = 0, b = 0, c<>0 일 경우를 처리한다
//- a = 0, b<>0 일 경우를 처리한다.
//- 판별식이 + 인 경우를 처리한다
//- 판별식이 - 인 경우를 처리한다
//- 판별식이 0 인 경우를 처리한다
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