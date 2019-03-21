#include <string>
#include <vector>
#include<iostream>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	double temp = sqrt(n);
	if (temp - (int)temp > 0)
	{
		answer = -1;
	}
	else
	{
		answer = (temp + 1) * (temp + 1);
	}

	return answer;
}

int main()
{
	cout<<solution(3);
}