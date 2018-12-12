#include<stdio.h>

int main(void)
{
	double lightSpeed = 300000.0;
	double distanceSunToEarth = 149600000;
	double arriveTime = distanceSunToEarth / lightSpeed;

	printf("빛의 속도는 %lfkm/s\n", lightSpeed);
	printf("지구에서 태양까지 거리는 %lfkm\n", distanceSunToEarth);
	printf("도달 시간은 %d분 %d초\n", (int)(arriveTime/60.0) , (int)arriveTime%60);

	return 0;
}