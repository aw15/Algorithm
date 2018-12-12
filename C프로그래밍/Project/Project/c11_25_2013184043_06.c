#include<stdio.h>
#include <stdlib.h>


int b_rand()
{
	float num = rand();
	if (num / RAND_MAX  >0.5f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i <5;++i)
	{
		printf("%d ", b_rand());
	}
}