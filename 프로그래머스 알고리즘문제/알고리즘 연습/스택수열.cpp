#include<string>
#include<stack>
#include<iostream>

using namespace std;

int main()
{


	int n = 0;
	cin >> n;

	stack<int> s;
	int m = 0;

	string answer;

	for (int i = 0; i < n; ++i)
	{
		
		int target = 0;
		cin >> target;

		if (m < target)
		{
			while (m < target)
			{
				m += 1;
				s.push(m);
				answer+='+';
			}
			answer += '-';
			s.pop();
		}
		else
		{
			if (s.top() == target)
			{
				answer += '-';
				s.pop();
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}



}