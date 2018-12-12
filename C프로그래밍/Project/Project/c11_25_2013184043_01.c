#include<stdio.h>


int even(int n)
{
	return n % 2 == 0 ? 1 : 0;
}
int absolute(int n)
{
	return n < 0 ? -1 * n : n;
}
int sign(int n)
{
	if (n == 0)
		return 0;
	if (n < 0)
		return -1;
	if (n > 0)
		return 1;
}

int main()
{
	
	int num = 0;
	
	if (scanf("%d", &num) != 1)
		return printf("Invalid Input\n");

	if (even(num) == 1)
		printf("even�� ���: ¦��\n");
	else
		printf("even�� ���: Ȧ��\n");


	printf("absolute�� ���: %d\n", absolute(num));
	
	if (sign(num) == 1)
		printf("sign�� ���: ���\n");
	else if(sign(num) == -1)
		printf("sign�� ���: ����\n");
	else
		printf("sign�� ���: 0\n");

}


