#include "stdafx.h"
#include<string>
#include<deque>
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define LEFT 0
#define RIGHT 1

bool FindNum(const std::deque<int>& testCase,const int num)
{
	int i = 0;
	int size = testCase.size();
	for (const auto& data: testCase)
	{
		if (data == num)
		{
			break;
		}
		i++;
	}

	if (i > size / 2)
	{
		return RIGHT;
	}
	else
	{
		return LEFT;
	}
}


int main()
{
	int max = 0;
	int targetRange = 0;
	std::deque<int> testCase;
	std::deque<int> target;
	int temp;

	cin >> max >> targetRange;

	for (int i = 1; i <= max; ++i)
	{
		testCase.push_back(i);
	}
	for (int i = 0; i < targetRange; ++i)
	{
		cin >> temp;
		target.push_back(temp);
	}

	int operationCount=0;
	
	while (!target.empty())
	{
		int front = testCase.front();
		if (target.front() == front)
		{
			target.pop_front();
			testCase.pop_front();
		}
		else
		{
			bool test = FindNum(testCase, target.front());
			if (test == RIGHT)
			{
				temp = testCase.back();
				testCase.pop_back();
				testCase.push_front(temp);
				operationCount++;
			}
			else
			{
				temp = testCase.front();
				testCase.pop_front();
				testCase.push_back(temp);
				operationCount++;
			}
		}
	}

	cout << operationCount<<"\n";

	return 0;
}