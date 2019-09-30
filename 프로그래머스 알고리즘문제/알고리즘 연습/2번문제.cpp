#include<vector>
#include<iostream>
#include<set>
using namespace std;


set<int> numbers;
int result = 0;

int max(const int a,const int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int Find(vector<int> cook_times, vector<vector<int>> order, int k)
{
	numbers.insert(k);



	bool isFind = false;
	int maxValue = 0;
	for (int i = 0; i < order.size(); ++i)
	{
		if (order[i][1] == k)
		{
			isFind = true;

			maxValue = max(maxValue,Find(cook_times, order, order[i][0]));
		}
	}
	if (isFind == false)
	{
		return cook_times[k - 1];
	}
	else
	{
		return cook_times[k - 1] + maxValue;
	}
	return 0;
}


vector<int> solution(vector<int> cook_times, vector<vector<int>> order, int k)
{
	vector<int> answer;

	int time =  Find(cook_times, order, k);

	answer.resize(2);
	answer[0] = numbers.size() - 1;
	answer[1] = time;


	return answer;
}

int main()
{
	auto answer = solution({ 5, 30, 15, 30, 35, 20, 4, 50, 40 }, {
		{2,4},
		{2,5},
		{3,4},
		{3,5},
		{1,6},
		{4,6},
		{5,6},
		{6,7},
		{8,9}
		},
		9
	);



	//for (auto data:numbers)
	//{
	//	cout << data << " " << endl;
	//}

	cout << answer[0] << " " << answer[1] << endl;
}