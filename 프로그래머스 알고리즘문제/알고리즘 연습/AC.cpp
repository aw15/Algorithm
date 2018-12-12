#include "stdafx.h"
#include"cstdio"
#include<iostream>
#include <deque>
#include<vector>
using std::cout;
using std::endl;
using std::cin;



int main()
{

	//D�� ù��° ���ڸ� ������ �Լ��̴�.
	//R�� �迭�� �ִ� ������ ������ �����´�.
	
	std::string command;
	short count = 0;

	
	cin >> count;
	for(int k=0;k<count;++k)
	{
		int size = 0;
		bool isError = false;
		bool isReverse = false;
		int x = 0;
		std::deque<int> test;
		char command[100001];
		int length = 0;
		int vectorsize = 0;


		cin >> size;
		int N;
		scanf("%s %d\n[", command, &N);

		while (1) {
			char c = getchar();
			// ���ڰ� ������ ���� ��*10 �� �� ����
			if (c >= '0' && c <= '9') x = x * 10 + c - '0';
			// �ƴ� ��� ���� ���� ���� ����
			else {
				if (x > 0) test.push_back(x);
				x = 0;
				if (c == ']') break;
			}
		}

		for (int i = 0;  command[i]; i++)//�̰� ��¿ �� ����.... 
		{
			if (command[i] == 'R')
			{
				isReverse = !isReverse;
			}
			else if (command[i] == 'D')
			{
				if (test.empty())
				{
					isError = true;
					break;
				}
				else if (isReverse)
				{
					test.erase(test.end()-1);
				}
				else
				{
					test.erase(test.begin());
				}
			}
		}
		if (isError)//�̰͵� ����̴�... ��¿�� ����
		{
			puts("error");
		}
		else
		{
			putchar('[');
			
			if (isReverse)
			{
				for (int i = vectorsize-1; i >=0; i--)
				{
					if (i == 0)
					{
						printf("%d" ,test[i]);
					}
					else
					{
						printf("%d,", test[i]);
					}
				}
			}
			else
			{
				for (int i = 0; i < vectorsize; i++)
				{
					if (i == vectorsize - 1)
					{
						printf("%d", test[i]);
					}
					else
					{
						printf("%d,", test[i]);
					}
				}
			}
			puts("]");
		}
	}


	return 0;
}