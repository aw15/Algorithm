#include<stdio.h>
#include<math.h>

float sin_degree(float degree)
{
	float rad = (degree*3.141592) / 180.0;
	return sin(rad);
}

int main()
{
	for (int i = 0; i <= 180; i += 10)
	{
		printf("sin(%d)ÀÇ °ª : %lf\n",i, sin_degree(i));
	}
}