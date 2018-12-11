

#include <string>
#include<iostream>
#include <vector>
#include<set>
#include <iterator>


using namespace std;


//������ ������ �������� �����濡 �����Ͽ����ϴ�.�� �� ���� ������ �����ϰ�� 
//��� ������ �������� �����Ͽ����ϴ�.
//
//�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 
//completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

string solution(vector<string> participant, vector<string> completion) {
	
	string answer = "";

	multiset<string> people;
	
	copy(completion.begin(), completion.end(), inserter(people, people.begin() ) );

	for (auto& name : participant)
	{
		auto iter = people.find(name);
		if (iter == people.end())
		{
			return name;
		}
		else
		{
			people.erase(iter);
		}
	}

	 return answer;
}

int main()
{
	auto temp = solution({ "leo","kiki","eden" }, { "eden","kiki" });
	cout << temp;
}