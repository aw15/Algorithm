#include<stdio.h>

int main(void)
{
	double lightSpeed = 300000.0;
	double distanceSunToEarth = 149600000;
	double arriveTime = distanceSunToEarth / lightSpeed;

	printf("���� �ӵ��� %lfkm/s\n", lightSpeed);
	printf("�������� �¾���� �Ÿ��� %lfkm\n", distanceSunToEarth);
	printf("���� �ð��� %d�� %d��\n", (int)(arriveTime/60.0) , (int)arriveTime%60);

	return 0;
}