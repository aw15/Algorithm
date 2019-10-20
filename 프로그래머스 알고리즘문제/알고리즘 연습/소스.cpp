#include <stdio.h>
#include<stdlib.h>

int main() {
	int num = 0;
	int i, t, r;

	scanf("%d", &num);
	int* so = (int*)malloc(sizeof(int)*num+1);


	for (int i = 1; i <= num; i++)
	{
		so[i] = 1;
	}

	for (int r = 2; r <= 1000; r++)
	{
		for (t = r * 2; t <= num; t += r)
		{
			so[t] = 0;
		}
	}

	for (int i = 2; i <= num; i++)
	{
		if (so[i] == 1)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
