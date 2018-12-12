#include<stdio.h>
#include<stdlib.h>

void arr_fill(int *A, int size)
{
	for (int i = 0; i < size; i++)
	{
		A[i] = rand();
	}
}

int main()
{
	srand(time(NULL));
	int a[10];
	arr_fill(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}