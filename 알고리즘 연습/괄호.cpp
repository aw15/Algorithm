#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>

using std::cout;
using std::endl;
using std::cin;

#define LEFT '('
#define RIGHT ')'

bool CheckBracket(const std::string& testCase)
{
	std::stack<char> testStack;


	if (testCase[0] == ')')
		return false;

	for (auto it = testCase.begin(); it != testCase.end(); ++it)
	{
		if (*it == LEFT)
		{
			testStack.push(*it);
		}
		else
		{
			if (!testStack.empty())
			{
				testStack.pop();
			}
			else
			{
				return false;
			}
		}
	}


	return testStack.empty();
}

int main()
{
	int count = 0;
	
	cin >> count;
	std::string input;

	for(int i=0;i<count;++i)
	{
		cin >> input;
		if (CheckBracket(input))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

}