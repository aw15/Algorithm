#include <string>
#include <vector>

#include<iostream>
using namespace std;
#define COL 0
#define BLANK 0x4
#define BO 1


#define DELETE 0
#define BUILD 1

using namespace std;



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


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	vector<vector<int>> pan;

	pan.resize(n);
	for (int i = 0; i < pan.size(); ++i)
	{
		pan[i].resize(n,BLANK);
	}


	for (int i = 0; i < build_frame.size(); ++i)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int building = build_frame[i][2];
		int instruction = build_frame[i][3];

		if (building == COL)
		{
			if (instruction == BUILD && (x == 0  || pan[x][y-1]  == COL || pan[x][y-1] == BO))
			{
					pan[x][y] = COL;
			}
		}
		Print(pan);
		//if (building == BO)
		//{
		//	if (instruction == BUILD && x-1 >= 0 && x + 1 < n)
		//	{
		//		if(pan[x-1][y]==BO && )

		//		if (pan[x][y] = COL)
		//			pan[x][y] = BO_AND_COL;
		//		else
		//			pan[x - 1][y] = BO;
		//	}
		//}
	}



	return answer;
}



int main()
{
	auto temp = solution(5, { {1, 0, 0, 1},{1, 1, 1, 1},{2, 1, 0, 1},{2, 2, 1, 1},{5, 0, 0, 1},{5, 1, 0, 1},{4, 2, 1, 1},{3, 2, 1, 1} });

	for (auto data : temp)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

}