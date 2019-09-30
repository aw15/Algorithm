#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



bool Check(string s)
{
	int len = s.size();
	int count = 0;


	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
		{
			count += 1;
		}
		else if (s[i] == ')' && count > 0)
		{
			count -= 1;
		}
		else if (s[i] == ')' && count <= 0)
		{
			count -= 1;
			break;
		}
	}

	if (count == 0)
	{
		//cout << "YES" << endl;
		return true;
	}
	else
	{
		//cout<< "NO" << endl;
		return false;
	}

	return false;
}


string solution(string p) {
	string answer = "";

	string u, v;
	int left = 0;
	int right = 0;

	if (p.size() == 0)
		return answer;

	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(')
			left += 1;
		else
			right += 1;


		if (left != 0 && right != 0 && left == right)
		{
			u.assign(p, 0, i+1);
			v.assign(p,i+1 , p.size() - 1);

			//cout << u << " " << v << endl;
			break;
		}
	}

	if (Check(u))
	{
		answer = u + solution(v);
	}
	else
	{
		answer = "(" + solution(v) + ")";
		u.erase(u.begin());
		u.erase(u.end() - 1);
		for (char& c : u)
		{
			if (c == '(')
				c = ')';
			else
				c = '(';
		}
		answer += u;
	}


	return answer;
}


int main()
{
	string s;



	cin >> s;
	
	cout << solution(s);

	

}