#include<stdio.h>
void exchange(const char* &a,const char* &b)
{
	auto temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	const char* p = "29��";
	const char* q= "9��";
	exchange(p, q);
	printf("%s %s", p, q);


	return 0;
}