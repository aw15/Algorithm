#include <string>
#include <vector>

using namespace std;


#include<iostream>

vector<int> solution(vector<int> prices) {
	vector<int> answer;


	for (int index = 0; index < prices.size(); index++)
	{
		int count = 0;
		for (int i = index+1; i < prices.size(); i++)
		{
			if (prices[index] <= prices[i])
				count++;
			else
			{
				count++;
				break;
			}
		}
		answer.push_back(count);
	}

	return answer;
}


int main()
{
	auto ret = solution({ 498,501,470,489 });
	for (auto data : ret)
	{
		cout << data << " ";
	}
}