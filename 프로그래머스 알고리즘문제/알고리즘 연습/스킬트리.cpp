#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string>
#include<algorithm>
using namespace std;

#include<iostream>



int FindSkill(const char* tree,const char* skill)
{

	int currentSkill = 0;

	for (int j = 0; j < strlen(skill); j++)
	{
		for (int z = currentSkill + 1; z < strlen(tree); z++)
		{
			if (skill[j] == tree[z])
			{
				return 0;
			}
			else if(skill[j] == tree[currentSkill])
			{
				currentSkill++;
			}
		}
	}

	return 1;

}


// skill_trees_len은 skill_trees의 길이입니다.
int solution(const char* skill,const char* skill_trees[], size_t skill_trees_len) {
	int answer = 0;


	for (int i = 0; i < skill_trees_len; i++)
	{
		answer += FindSkill(skill, skill_trees[i]);
	}

	return answer;
}


int main()
{
	const char* skill_trees[] = { "BACDE", "CBADF", "AECB", "BDA" };
	cout << solution("CBD", skill_trees, 4);


}