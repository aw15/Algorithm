#include<stdio.h>


//숫자 n 을 scanf() 로 입력받고 1부터 n 사이의 수 중 소수를 한 라인에 하나씩 
//출력하는 프로그램을 작성하여 제출한다.
//
//모두 몇 개인지 확인하기 위해 각 라인에 넘버링을 하도록 한다.
//
//출력 예 :
//
//
//
//#1: 2
//
//#2: 3
//
//#3: 5
//
//#4: 7
//
//#5: 11
//
//.
//
//.
//
//.
//
//
//
//프로그램은 c11_21_학번.c 로 첨부하고 프로그램 실행 결과는 과제 본문에 붙여넣기 하도록 한다.
//
//
//
//요구사항:
//
//-소수인지 판별하는 함수 isPrime() 을 작성하고 호출한다. (함수이름 반드시 지킬 것)
//
//- c99 스타일에 맞도록 변수를 선언한다
//
//- 경고가 나오지 않도록 한다.
//
//- C표준만을 사용한다.
//
//- scanf 의 리턴값을 반드시 확인한다.


int isPrime(int num)
{
	int index = 1;
	for (int i = 2; i < num; i++)
	{
		int count = 0;
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			printf("#%d: %d\n", index, i);
			index += 1;
		}
	}
}

int main(void)
{
	int num = 0;
	int ret = scanf("%d", &num);
	if (ret != 1)
	{
		printf("invalid input\n");
		return -1;
	}

	isPrime(num);

}