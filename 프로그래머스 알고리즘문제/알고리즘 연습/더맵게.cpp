#include <string>
#include <vector>
#include<iostream>

using namespace std;

void Mix(vector<int>& scoville, int K,int index)
{
	for (int i = 0; i < scoville.size(); i++)
	{
		if (i == index)
			continue;
		if (scoville[index])
		{

		}
	}
}


int solution(vector<int> scoville, int K) {
	int answer = 0;

	for (int i = 0; i < scoville.size(); i++)
	{
		if (scoville[i] < K)
		{
			Mix(scoville, K, i);
		}

	}


	return answer;
}


int main();