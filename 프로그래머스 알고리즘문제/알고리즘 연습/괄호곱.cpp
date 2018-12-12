#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>

using std::cout;
using std::endl;
using std::cin;

#define CIR_LEFT '('
#define CIR_RIGHT ')'

#define RECT_LEFT '['
#define RECT_RIGHT ']'

void CalculationQuatation(int& answer,std::vector<char>& quatation)
{
	if (quatation.size() == 3)
	{
		answer += quatation[0] * quatation[1];
	}
	else if(quatation.size() == 2)
	{
		if (quatation[1] == '+')
		{
			answer += quatation[0];
		}
		if (quatation[1] == '*')
		{
			answer *= quatation[0];
		}
	}
	quatation.clear();
}


int CalculateBracket(const std::string& testCase)
{
	std::stack<char> testStack;
	std::vector<char> quatation;
	int answer = 0;


	if (testCase[0] == ')'|| testCase[0] == ']')
		return 0;

	int length = testCase.length();

	for (int i = 0; i<length; ++i)
	{



		if (testCase[i] == CIR_LEFT)
		{
			testStack.push(testCase[i]);
		}
		else if (testCase[i] == RECT_LEFT)
		{
			testStack.push(testCase[i]);
		}
		else if (testCase[i] == CIR_RIGHT)
		{
			if (testStack.empty())
			{
				return 0;
			}
			else if(testStack.top() == RECT_LEFT)
			{
				return 0;
			}
			else
			{
				quatation.push_back(2);
				testStack.pop();
			}
		}
		else
		{
			if (testStack.empty())
			{
				return 0;
			}
			else if (testStack.top() == CIR_LEFT)
			{
				return 0;
			}
			else
			{
				quatation.push_back(3);
				testStack.pop();
			}
		}
		if (i != 0)
		{
			if ((testCase[i - 1] == CIR_RIGHT && testCase[i] == CIR_LEFT) || (testCase[i - 1] == CIR_RIGHT && testCase[i] == RECT_LEFT))
			{
				quatation.push_back('+');
				CalculationQuatation(answer, quatation);
			}
			if ((testCase[i - 1] == RECT_RIGHT && testCase[i] == CIR_LEFT) || (testCase[i - 1] == RECT_RIGHT && testCase[i] == RECT_LEFT))
			{
				quatation.push_back('+');
				CalculationQuatation(answer, quatation);
			}
			if ((testCase[i - 1] == CIR_RIGHT && testCase[i] == CIR_RIGHT) || (testCase[i - 1] == CIR_RIGHT && testCase[i] == RECT_RIGHT))
			{
				quatation.push_back('*');
				CalculationQuatation(answer, quatation);
			}
			if ((testCase[i - 1] == RECT_RIGHT && testCase[i] == CIR_RIGHT) || (testCase[i - 1] == RECT_RIGHT && testCase[i] == RECT_RIGHT))
			{
				quatation.push_back('*');
				CalculationQuatation(answer, quatation);
			}
		}

	}

	if (!testStack.empty())
		return 0;

	return answer;
}


int main()
{
	std::string input;

	cin >> input;
	cout << CalculateBracket(input)<<endl;

}