#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int arr[] = { 4,1,7,4,2,6,4,1,5,3,7,5 };

		if (b % 7 == arr[a - 1] % 7)
		{
			answer = "MON";
		}
		if (b % 7 == (arr[a - 1] + 1) % 7)
		{
			answer = "TUE";
		}
		if (b % 7 == (arr[a - 1] + 2) % 7)
		{
			answer = "WED";
		}
		if (b % 7 == (arr[a - 1] + 3) % 7)
		{
			answer = "THU";
		}
		if (b % 7 == (arr[a - 1] + 4) % 7)
		{
			answer = "FRI";
		}
		if (b % 7 == (arr[a - 1] + 5) % 7)
		{
			answer = "SAT";
		}
		if (b % 7 == (arr[a - 1] + 6) % 7)
		{
			answer = "SUN";
		}

	return answer;
}



int main()
{
	cout << solution(1, 1)<<endl;
	cout << solution(1, 31) << endl;
	cout << solution(5, 24) << endl;
}