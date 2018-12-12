#include <string>
#include <vector>
using namespace std;


#include<iostream>


int number1(vector<int>& answers) {
	int arr[] = { 1,2,3,4,5 };
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == arr[i % 5]) count += 1;
	}

	return count;
}

int number2(vector<int>& answers) {
	int arr[] = { 2,1,2,3,2,4,2,5 };
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == arr[i % 8]) count += 1;
	}

	return count;
}

int number3(vector<int>& answers) {
	int arr[] = { 3,3,1,1,2,2,4,4,5,5 };
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == arr[i % 10]) count += 1;
	}

	return count;
}

int getMax(int a, int b) {
	return a < b ? b : a;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;


	int count[3] = { number1(answers), number2(answers), number3(answers) };

	int max = -1;
	for (int i = 0; i < 3; i++)
		if (max < count[i]) max = count[i];
	for (int i = 0; i < 3; i++)
		if (max == count[i]) answer.push_back(i + 1);

	return answer;
}


int main()
{
	auto temp = solution({ 1,2,3,4,5 ,1,2,2,3,4,5,6,7,3,3});
	for (auto data : temp)
	{
		cout << data << endl;
	}
}