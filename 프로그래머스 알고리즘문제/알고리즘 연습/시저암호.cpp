#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s, int n) {
	string answer = "";


	for (auto& c : s)
	{
		if (c == ' ')
		{
			answer += c;
			continue;
		}
		if (isupper(c))
		{
			if ((c + n) > 'Z')
			{
				answer += (char)('A' + ((c + n) - 'Z' - 1));
			}
			else
			{
				answer += c + n;
			}
		}
		else if (islower(c))
		{
			if ((c + n) > 'z')
			{
				answer += (char)('a' + ((c + n) - 'z' - 1));
			}
			else
			{
				answer += c + n;
			}
		}
	}
	return answer;
}