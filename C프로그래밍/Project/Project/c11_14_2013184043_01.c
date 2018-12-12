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
		printf("모음입니다.\n");
		break;
	default:
		printf("자음입니다.\n");
		break;
	}
	return 0;
}