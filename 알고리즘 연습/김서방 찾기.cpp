#include<iostream>



#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	
	auto iter = find(seoul.begin(), seoul.end(), "Kim");
	long long index = iter - seoul.begin();

	answer	= "김서방은 " + to_string(index) + "에 있다";

	return answer;
}

int main()
{
	auto temp = solution({"kim,""jane"});
	cout << temp;
}