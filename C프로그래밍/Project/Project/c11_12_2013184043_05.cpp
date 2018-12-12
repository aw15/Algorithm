#include<stdio.h>
void exchange(const char* &a,const char* &b)
{
	auto temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	const char* p = "29ÀÏ";
	const char* q= "9¿ù";
	exchange(p, q);
	printf("%s %s", p, q);


	return 0;
}