#include<stdio.h>


int main(void)
{ 
	char c;
	printf("input charactor : ");
	int retval = scanf("%c", &c);
	if(retval != 1)
	{
		printf("invalid input\n");
		return -1;
	}
	
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'u':
	case 'o':
		printf("�����Դϴ�.\n");
		break;
	default:
		printf("�����Դϴ�.\n");
		break;
	}
	return 0;
}