#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;

#include<iostream>
//전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 
//여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 
//체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();

	for (auto& cloth : lost)
	{
		auto iter = find(reserve.begin(), reserve.end(), cloth);
		if (iter != reserve.end())
		{
			answer++;
			reserve.erase(iter);
			continue;
		}
		iter = find(reserve.begin(), reserve.end(), cloth - 1);
		if (iter != reserve.end())
		{
			answer++;
			reserve.erase(iter);
			continue;
		}
		iter = find(reserve.begin(), reserve.end(), cloth + 1);
		if (iter != reserve.end())
		{
			answer++;
			reserve.erase(iter);
			continue;
		}
	}

	return answer;
}

int main()
{
	cout << solution(5, { 2,4 }, { 1,3,5 });
}


