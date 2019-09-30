#include <string>
#include <vector>
#include<iostream>

using namespace std;


bool Check(vector<vector<int>>& lock)
{
	for (int i = 0; i < lock.size(); ++i)
	{
		for (int j = 0; j < lock[i].size(); ++j)
		{
			if (lock[i][j] != 1)
			{
				return false;
			}
		}
	}
	return true;
}


bool Move(int i,int j,vector<vector<int>>& key, vector<vector<int>>& lock)
{
	int lockX = 0; 
	int lockY = 0;

	vector<vector<int>> temp = lock;

	for (int x = i; x < key.size(); ++x)
	{
		for (int y = j; y < key[x].size(); ++y)
		{
			if (key[x][y] == 1 && temp[lockX][lockY] == 0)
				temp[lockX][lockY] = 1;

			lockY += 1;
		}
		lockX += 1;
	}
	return Check(temp);
}

bool Answer(vector<vector<int>>& key, vector<vector<int>>& lock)
{
	vector<vector<int>> temp;
	for (int i = 0;i< 2*key.size() + lock.size() - 2;++i)
	{
		for (int j = 0; j < 2*key.size() + lock.size() - 2; ++j)
		{
			if(i  key.size() - 1)
				temp
		}
	}
}

void Print(vector<vector<int>>& temp)
{
	for (int i = 0; i < temp.size(); ++i)
	{
		for (int j = 0; j < temp[i].size(); ++j)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	vector<vector<int>> temp;
	temp.resize(key.size());

	for (int i = 0; i < key.size(); ++i)
	{
		for (int j = key.size()-1 ; j >= 0; --j)
		{
			temp[i].push_back(key[j][i]);
		}
	}

	temp.clear();
	temp.resize(key.size());
	
	int index = 0;
	for (int i = key.size()-1 ; i >= 0; --i)
	{
		for (int j = key.size()-1; j >= 0; --j)
		{
			temp[index].push_back(key[i][j]);
		}
		index += 1;
	}

	temp.clear();
	temp.resize(key.size());

	index = 0;
	for (int i = key.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < key.size(); ++j)
		{
			temp[index].push_back(key[j][i]);
		}
		index += 1;
	}

	return answer;
}


void main()
{
	cout << solution({ { 0,0,0 }, { 1,0,0 }, { 0,1,1 } }, { {1,1,1},{1,1,0},{1,0,1} });
}