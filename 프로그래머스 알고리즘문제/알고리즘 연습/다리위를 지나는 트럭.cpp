#include"pch.h"
#include <string>
#include <vector>

using namespace std;

//Ʈ���� 1�ʿ� 1��ŭ �����̸�, �ٸ� ���̴� bridge_length�̰� �ٸ��� ���� weight���� �ߵ��ϴ�.
//�� Ʈ���� �ٸ��� ������ ������ ���� ���, �� Ʈ���� ���Դ� ������� �ʽ��ϴ�.

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int timeCount = 1;
	int bridgeTruck;

	int count = 0;
	for (int i = 0; i < truck_weights.size();)
	{
		timeCount++;
	}
	answer = timeCount;

	return answer;
}

int main()
{
	solution(2, 10, { 7,4,5,6 });

}
