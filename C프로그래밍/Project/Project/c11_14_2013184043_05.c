#include<stdio.h>


int main(void)
{
	int height, age;
	printf("input height age : ");
	int retval = scanf("%d %d", &height, &age);
	if (retval != 2 || height <= 0 || age <= 0)
	{
		printf("invalid input\n");
		return -1;
	}

	if (height > 140 && age > 10)
		printf("Ÿ�� �����ϴ�.\n");
	else
		printf("�˼��մϴ�.\n");

	return 0;
}