#include"pch.h"
#include <string>
#include <vector>

using namespace std;

//트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딥니다.
//※ 트럭이 다리에 완전히 오르지 않은 경우, 이 트럭의 무게는 고려하지 않습니다.

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
