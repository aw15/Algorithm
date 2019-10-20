#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> input;
	vector<int> output;
	int counting[100 + 1] = {0,};
	int countingSum[100 + 1] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		input.push_back(rand() % 100+1);
		counting[*(input.end() - 1)]++;
	}

	countingSum[0] = counting[0];
	for (int i = 1; i < 101; i++)
	{
		countingSum[i] = countingSum[i - 1] + counting[i];
	}
	output.resize(input.size());

	for (int i = 0; i < input.size(); ++i)
	{
		int index = countingSum[input[i]];
		output[index - 1] = input[i];
		countingSum[input[i]] -= 1;
	}


	for (auto data : input)
	{
		cout << data << " ";
	}
	cout << endl;
	for (auto data : output)
	{
		cout << data << " ";
	}
	cout << endl;
}