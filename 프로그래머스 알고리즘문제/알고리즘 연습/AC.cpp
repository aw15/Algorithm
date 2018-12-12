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

	//D는 첫번째 숫자를 버리는 함수이다.
	//R은 배열에 있는 숫자의 순서를 뒤집는다.
	
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
			// 숫자가 나오면 현재 수*10 한 뒤 더함
			if (c >= '0' && c <= '9') x = x * 10 + c - '0';
			// 아닐 경우 현재 수를 덱에 넣음
			else {
				if (x > 0) test.push_back(x);
				x = 0;
				if (c == ']') break;
			}
		}

		for (int i = 0;  command[i]; i++)//이건 어쩔 수 없지.... 
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
		if (isError)//이것도 출력이니... 어쩔수 없지
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