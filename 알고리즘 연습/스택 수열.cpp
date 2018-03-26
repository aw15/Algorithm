#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int size = 0;
	int currentNum = 1;
	char command = 0;
	std::queue<int> data;
	std::queue<char> commands;
	std::stack<int> numbers;


	cin >> size;

	int temp;

	for (int i=0;i<size;++i)
	{
		cin >> temp;
		data.push(temp);
	}

	int top;

	while (!data.empty())
	{
		
		if (numbers.empty())
			top = -1;
		else
			top = numbers.top();

		if (data.front() > top)
		{
			numbers.push(currentNum);
			commands.push('+');
			currentNum++;
		}
		else if (data.front() < top)
		{
			cout << "NO\n";
			return 0;
		}
		else
		{
			numbers.pop();
			data.pop();
			commands.push('-');
		}

	}

	size = commands.size();

	for (int i = 0; i < size; ++i)
	{
		cout<<commands.front()<<"\n";
		commands.pop();
	}
	

	return 0;
}