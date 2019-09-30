#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<char> left;
	stack<char> right;

	string s;
	cin >> s;

	int n;
	cin >> n;

	for (int i = 0; i < s.size(); ++i)
	{
		left.push(s[i]);
	}

	while (n--)
	{
		char command;
		cin >> command;
		if (command == 'L')
		{
			if (!left.empty())
			{
				char temp = left.top();
				left.pop();
				right.push(temp);
			}
		}
		else if (command == 'D')
		{
			if (!right.empty())
			{
				char temp = right.top();
				right.pop();
				left.push(temp);
			}
		}
		else if (command == 'B')
		{
			if(!left.empty())
				left.pop();
		}
		else
		{
			char temp;
			cin >> temp;
			left.push(temp);
		}
	}

	string leftString;
	while (!left.empty())
	{
		leftString.insert(leftString.begin(), left.top());
		left.pop();
	}
	cout << leftString;
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}
}