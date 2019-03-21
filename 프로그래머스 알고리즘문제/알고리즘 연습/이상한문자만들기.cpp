#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
	string answer = "";
	
	//istream i(answer);
	istringstream a(s);
	string temp;
	while (getline(a, temp, ' '))
	{
		for (int i = 0; i < temp.length(); i ++)
		{
			temp[i] = tolower(temp[i]);
			if(i%2==0)
				temp[i] = toupper(temp[i]);
		}
		answer += temp + " ";
	}

	answer.erase(answer.end() - 1);
	while (answer.size() < s.size())
	{
		answer.append(" ");
	}


	return answer;
}


int main()
{

	auto temp = solution("a   ");
	cout << temp;
	cout << "a";

}