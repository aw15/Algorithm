#include<stdio.h>


//- ��ȣ 1������ 15������ �ĺ��� ��ǥ���� ���Ѵ�
//- ��ǥ ������ ����Ѵ�
//- ÷���� ������ �����ͷ� ����Ѵ�.
//- �ϼ� ��.c ������ ÷���Ͽ� �����Ѵ�.���� �̸��� c11_28_�й�.c �� �ǵ��� �Ѵ�.
//- ��� ����� �ؽ�Ʈ ���·� ���� ������ ����&�ٿ��ֱ� �Ѵ�
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