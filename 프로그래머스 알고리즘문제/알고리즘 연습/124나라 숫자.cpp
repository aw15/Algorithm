#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

//못풀었다 아오

char num_remain[] = { '4','1','2'};

char num_divide[] = { '1','2','4' };

string solution(int n) {
	string answer = "";
	

	if (n < 3)
	{
		answer += num_remain[n];
		return answer;
	}


	while(n>=3)
	{	
		if(n%3 == 0)
			answer += num_remain[0];
		else
		{
			answer += num_remain[n % 3];
		}
		
		n = n / 3;
	}
	
	if(n%3 !=0)
		answer += num_remain[n];




	//reverse(answer.begin(), answer.end());

	return answer;
}



int main()
{
	cout << solution(3);
}