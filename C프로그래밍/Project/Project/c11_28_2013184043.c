#include<stdio.h>


//- 기호 1번부터 15번까지 후보의 득표수를 구한다
//- 득표 비율를 출력한다
//- 첨부한 파일을 데이터로 사용한다.
//- 완성 후.c 파일을 첨부하여 제출한다.파일 이름은 c11_28_학번.c 가 되도록 한다.
//- 출력 결과는 텍스트 형태로 과제 본문에 복사&붙여넣기 한다
#define SIZE 15
int main()
{
	int candidate[SIZE] = {0};
	int temp=0;
	int count = 0;
	while (scanf("%d", &temp) == 1)
	{
		count += 1;
		candidate[temp - 1]++;
	}

	printf("Total votes: %d\n", count);
	for (int i = 0; i < SIZE; ++i)
	{
		printf("#%3d %7d %6.3f%%\n", i + 1, candidate[i], candidate[i] / (float)count * 100);
	}

}