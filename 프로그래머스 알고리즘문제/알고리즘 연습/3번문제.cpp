#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	answer.reserve(queries.size());

	for (int i = 0; i < queries.size(); ++i)
	{
		int answerCount = 0;

		for (int j = 0; j < words.size(); ++j)
		{
			if (words[j].size() != queries[i].size())
				continue;

			bool isAnswer = true;

			for (int wordIndex =0 ; wordIndex < words.size() ; ++wordIndex)
			{
				if (words[j][wordIndex] != queries[i][wordIndex] && queries[i][wordIndex] != '?')
				{
					isAnswer = false;
					break;
				}
		
			}

			if (isAnswer)
				answerCount += 1;
		}
		answer.push_back(answerCount);
	}


	return answer;
}


int main()
{
	auto temp = solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, {"fro??", "????o", "fr???", "fro???", "pro?" });

	for (auto data : temp)
	{
		cout << data << endl;
	}
}