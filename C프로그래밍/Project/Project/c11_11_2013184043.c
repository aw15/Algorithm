#include<stdio.h>

//1 = 00y:00w : 00d : 00h : 00m : 01s
//2 = 00y : 00w : 00d : 00h : 00m : 02s
//3 = 00y : 00w : 00d : 00h : 00m : 03s
//10 = 00y : 00w : 00d : 00h : 00m : 10s
//12345 = 00y : 00w : 00d : 04h : 25m : 45s

int main(void)
{ 
	int second = 0, minute = 0, hour = 0 ,  day=0;
	int week = 0, year = 0;
	int input = 0;
	while (1)
	{
		int ret = scanf("%d", &input);
		if (ret != 1)
			break;
		if (input < 0)
			break;
		second = input;
		minute = second / 60; // 입력받은 sec를 60으로 나누면 분(min)
		hour = minute / 60; // min의 값을 60으로 나누면 시(hour)
		day = hour / 24;
		//week = day / 7;
		year = day / 365;

		second = second % 60; // 시분초로 바꿔주는 것이므로, sec를 60으로 나눠 그 나머지가 남은 초
		minute = minute % 60; // 12줄과 마찬가지로, min을 60으로 나눠 그 나머지가 남은 분
		hour = hour % 24;
		day = day % 365;

		week = day / 7;
		day -= week * 7;	

		printf("%d = %02dy : %02dw : %02dd : %02dh : %02dm : %02ds\n",input, year, week, day, hour, minute, second);
	}

	return 0;
}