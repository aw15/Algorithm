// 알고리즘 연습.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
class Stack
{
public:
	Stack(int size)
	{
		data = new int[size];
		max = size;
	}

	void Push(const int& num)
	{
		if (sp<max)
		{
			data[++sp] = num;
		}
	}
	void Pop(int& num)
	{
		if (sp > min)
		{
			num = data[sp];
			sp--;
		}
		else
			num = -1;
	}
	void Top(int& num)
	{
		if (sp > min)
		{
			num = data[sp];
		}
		else
			num = -1;
	}
	int Emtpy()
	{
		if (sp == -1)
			return 1;
		else
			return 0;
	}
	int Size()
	{
		if (sp == -1)
			return 0;
		else
			return sp+1;
	}
private:
	int* data=nullptr;
	int sp = -1;
	int max = 0;
	int min = -1;
};




int main()
{
	int count = 0;
	std::string command;
	int input = 0, output = 0;
	Stack stack{ 10000 };


	cin >> count;
	while (count--)
	{
		
		cin >> command;
		if (command == "push")
		{
			cin >> input;
			stack.Push(input);
		}
		else if (command == "pop")
		{
			stack.Pop(output);
			cout << output << "\n";
		}
		else if (command == "top")
		{
			stack.Top(output);
			cout << output << "\n";
		}
		else if (command == "size")
		{
			cout << stack.Size() << "\n";
		}
		else if (command == "empty")
		{
			cout << stack.Emtpy() << "\n";
		}

	}


    return 0;
}

