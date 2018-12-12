#pragma once

#define MapSize 18

struct CheckBoard_2012182034{
	int player;
	int weight;
};

CheckBoard_2012182034 pos[MapSize][MapSize] = { 0,0 };

int weightcheck[8][2] = {
	{ -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },
	{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 }
};

void WhiteAttack_2012182034(int* x, int* y);
void WhiteDefence_2012182034(int x, int y);
void BlackAttack_2012182034(int* x, int* y);
void BlackDefence_2012182034(int x, int y);

void InitBoard_2012182034();
void BruteForceAI_2012182034();
void SelectPos_2012182034();

int fx = 9;
int fy = 9;
bool first = true;

void WhiteAttack_2012182034(int* x, int* y) {
	if (pos[fx][fy].player == 0)
		pos[fx][fy].player = 2;

	x = &fx;
	y = &fy;
}

void WhiteDefence_2012182034(int x, int y) {
	pos[x][y].player = 1;
	BruteForceAI_2012182034();
	SelectPos_2012182034();
}

void BlackAttack_2012182034(int* x, int* y) {
	if (first)
	{
		InitBoard_2012182034();
		first = false;
	}
	if(pos[fx][fy].player == 0)
		pos[fx][fy].player = 2;
	
	x = &fx;
	y = &fy;
}

void BlackDefence_2012182034(int x, int y) {
	pos[x][y].player = 1;
	BruteForceAI_2012182034();
	SelectPos_2012182034();
}

void BruteForceAI_2012182034()
{
	//가중치 초기화
	for (int i = 0; i < MapSize; i++)
		for (int j = 0; j < MapSize; j++)
			pos[i][j].weight = 0;
	
	//가중치 계산
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			if (pos[i][j].player = 1)
			{
				for (int ch = 0; ch = 8; ch++)
				{
					int count = 1;
					int dx = i, dy = j;


					while (pos[dx][dy].player == 1 && dx >= 0 && dy >= 0
						&& dx <= MapSize && dy <= MapSize) {

						if (i + weightcheck[ch][0] >= 0 && j + weightcheck[ch][1] >= 0
							&& i + weightcheck[ch][0] <= MapSize && j + weightcheck[ch][1] >= MapSize)
							for (int c = 0; c<count; c++)
								pos[i + weightcheck[ch][0]][j + weightcheck[ch][1]].weight += 1;

						count++;
						dx += weightcheck[ch][0];
						dy += weightcheck[ch][1];
					}
				}
			}
			else if (pos[i][j].player = 2)
			{
				for (int ch = 0; ch = 8; ch++)
				{
					int count = 1;
					int dx = i, dy = j;

					while (pos[dx][dy].player == 1 && dx >= 0 && dy >= 0
						&& dx <= MapSize && dy <= MapSize) {

						if (i + weightcheck[ch][0] >= 0 && j + weightcheck[ch][1] >= 0
							&& i + weightcheck[ch][0] <= MapSize && j + weightcheck[ch][1] >= MapSize)
							for (int c = 0; c<count; c++)
								pos[i + weightcheck[ch][0]][j + weightcheck[ch][1]].weight += 1;

						count++;
						dx += weightcheck[ch][0];
						dy += weightcheck[ch][1];
					}
				}
			}
		}
	}
}

void InitBoard_2012182034()
{
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			pos[i][j] = { 0,0 };
		}
	}
}

void SelectPos_2012182034()
{
	int select[3] = { 0 };
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			if (pos[i][j].player == 0 && select[0] < pos[i][j].weight)
			{
				select[0] = pos[i][j].weight;
				select[1] = i;
				select[2] = j;
			}
		}
	}

	fx = select[1];
	fy = select[2];
}