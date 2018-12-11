#include <string>
#include <vector>

#include<iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	answer.emplace_back(arr[0]);
	
	for (int i = 1; i < arr.size(); ++i)
	{
		if (answer.back() != arr[i])
		{
			answer.emplace_back(arr[i]);
		}
	}

	return answer;
}

int main()
{
	auto temp = solution({ 1,1,3,3,0,1,1 });
	for (auto& data : temp)
	{
		cout << data << " ";
	}
}