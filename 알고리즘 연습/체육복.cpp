#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;

#include<iostream>
//��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, 
//������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, 
//ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

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


