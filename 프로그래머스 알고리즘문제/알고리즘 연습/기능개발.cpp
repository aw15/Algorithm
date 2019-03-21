#include <string>
#include <vector>

#include<iostream>

using namespace std;



vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> workDuration;
	
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++)
	{
		int num = ceil((100 - progresses[i]) / (float)speeds[i]);

		workDuration.push_back(num);
	}
	

	
	

	for (int i = 0; i < workDuration.size(); i++)
	{
		int currentWork = 1;
		int value = workDuration[i];
		for (int j = i+1; j < workDuration.size(); j++)
		{
			if (value >= workDuration[j])
			{
				currentWork += 1;
				workDuration.erase(workDuration.begin() + j);
			}	
		}
		answer.push_back(currentWork);
	}

	return answer;
}


int main()
{
	auto arr = solution({ 15, 1, 14, 9, 29, 25, 17, 24, 4, 27, 7, 19, 29, 14, 23, 4, 21, 3, 8, 14 }, { 9, 11, 21, 16, 11, 21, 7, 5, 6, 30, 11, 24, 26, 18, 20, 18, 15, 30, 7, 18 });
	for (auto data : arr)
	{
		cout << data << endl;
	}
}