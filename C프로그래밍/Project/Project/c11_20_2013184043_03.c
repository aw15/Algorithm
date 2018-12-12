#include<stdio.h>


int main(void)
{

	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 6; j++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}