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
	int count = 0;
	std::queue<int> myqueue;
	std::string command;
	int input = 0;
	cin >> count;

	while (count--)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> input;
			myqueue.push(input);
		}
		else if (command == "pop")
		{
			if (!myqueue.empty())
			{
				cout << myqueue.front() << "\n";
				myqueue.pop();
			}
			else
				cout << "-1\n";
			
		}
		else if (command == "front")
		{
			if(!myqueue.empty())
				cout << myqueue.front() << "\n";
			else
				cout  << "-1\n";
		}
		else if (command == "size")
		{
			cout << myqueue.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << myqueue.empty() << "\n";
		}
		else if (command == "back")
		{
			if (!myqueue.empty())
			{
				cout << myqueue.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}

	}
}