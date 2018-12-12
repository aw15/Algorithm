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
		minute = second / 60; // �Է¹��� sec�� 60���� ������ ��(min)
		hour = minute / 60; // min�� ���� 60���� ������ ��(hour)
		day = hour / 24;
		//week = day / 7;
		year = day / 365;

		second = second % 60; // �ú��ʷ� �ٲ��ִ� ���̹Ƿ�, sec�� 60���� ���� �� �������� ���� ��
		minute = minute % 60; // 12�ٰ� ����������, min�� 60���� ���� �� �������� ���� ��
		hour = hour % 24;
		day = day % 365;

		week = day / 7;
		day -= week * 7;	

		printf("%d = %02dy : %02dw : %02dd : %02dh : %02dm : %02ds\n",input, year, week, day, hour, minute, second);
	}

	return 0;
}