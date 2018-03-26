#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include <math.h>

using std::cout;
using std::endl;
using std::cin;


int main()
{
	int count=0;
	int max, rank;
	std::queue<int> numbers;

	cin >> max >> rank;
	for(int i=1;i<=max;++i)
	{
		numbers.push(i);
	}

	int i = 1;
	cout << "<";
	while (!numbers.empty())
	{
		if (i%rank == 0)
		{
			if (numbers.size() == 1)
			{
				cout << numbers.front();
			}
			else
			{
				cout << numbers.front() << ", ";
			}
			numbers.pop();

		}
		else
		{
			numbers.push(numbers.front());
			numbers.pop();
		}
		i++;
	}

	cout << ">";

}