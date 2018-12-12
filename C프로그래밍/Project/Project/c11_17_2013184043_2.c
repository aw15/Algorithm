//1. 숫자를 입력하면 1부터 해당 숫자까지 합을 구하는 프로그램을 작성한다.
//2. 숫자를 입력하면 1부터 해당 숫자까지 곱을 구하는 프로그램을 작성한다.
//
//프로그램은 숫자 하나를 입력받고 결과로 숫자 하나를 출력한다.
//문자를 입력하거나 입력을 종료하면 프로그램은 적절한 안내 메시지를 출력한 후 종료한다.
//while 을 사용한다.
//
//파일 이름은 c11_17_학번_1.c 와 c11_17_학번_2.c 가 되도록 한다.
//
//*중요* 과제 본문에 곱셈의 경우 몇 을 입력했을 때까지 정상적인 답이 출력되는지 적도록 한다.


#include<stdio.h>

int main(void)
{
	int input = 0;
	int ret = scanf("%d", &input);
	if (ret != 1)
	{
		printf("invalid input\n");
		return -1;
	}
	int sum = 1;
	int index = 1;
	
	while (index <= input)
	{
		sum *= index;
		index++;
	}

	printf("result = %d\n", sum);
	return 0;
}