#include "Omok_2013184043.h"

#define BLACK 'b'
#define WHITE 'w'
#define COMMON '0'
#define HINT '4'
#define MAX 19
#define TABLEMAX 21

enum Direction { N, NE, E, SE, S, SW, W, NW };
enum Result { NOPUT = 0, THREE = 50, THREE_FOUR = 60, FOUR = 70, WIN = 10000 };


pair<int, int> AI(char mine, char opposite);
bool IsUnavailable(const int* table);
int DefenceJudgement(int x, int y, const int* table, char mine);
int AttackJudgement(int x, int y, const int* table, char mine);
void BlockSituation(int v, int* table);
void Verify(const int& i, const int& j, const char& stone, int* table);
int CountStone(const int x, const int y, const char stone, const Direction d, bool firstBlank, int count);


static bool first = true;


char basePan[MAX][MAX] = { {'0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0' ,'0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0' ,'0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0' ,'0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0' ,'0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0' ,'0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' },
{ '0','0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' }
};


const pair<int,int> moving[8] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };
//------------------------------------------------------------------------------------------------


void BlackAttack_2013184043(int *x, int *y)
{
	//int inputX=0, inputY=0;
	//cout << "ÁÂÇ¥ÀÔ·Â(ex)1 2): ";
	//cin >> inputX;
	//cin >> inputY;
	//*y = inputX;
	//*x = inputY;
	if (first)
	{
		*x = 10;
		*y = 9;
		first = false;
		basePan[*x][*y] = BLACK;
	}
	else {
		
		auto returnData = AI(BLACK, WHITE);
		*x = returnData.first;
		*y = returnData.second;
		
		basePan[*x][*y] = BLACK;
	}
}
void WhiteDefence_2013184043(int x, int y)
{
	basePan[x][y] = BLACK;
}
void WhiteAttack_2013184043(int *x, int *y)
{
	auto returnData = AI(WHITE, BLACK);
	*x = returnData.first;
	*y = returnData.second;
	
	basePan[*x][*y] = WHITE;
}
void BlackDefence_2013184043(int x, int y)
{
	basePan[x][y] = WHITE;
}
  
pair<int, int>  AI(char mine, char opposite)//³ªÀÇ µ¹ »ö±ò
{
	int judgementTable[MAX][MAX];
	int table[21] = { 0 };
	pair<int,int> BestSu = { -1,-1 };
	int maxJudge = 0;
	int tempJudge = 0;

	std::fill(&judgementTable[0][0], &judgementTable[MAX - 1][MAX - 1], 0);

	for (int i = 0; i < MAX; i++)
	{
		int v = 0;
		for (int j = 0; j < MAX; ++j)
		{
			if (basePan[j][i] == COMMON)
			{
				std::fill(&table[0], &table[TABLEMAX - 1], 0);

				Verify(j, i, opposite, table);
				tempJudge = DefenceJudgement(j, i, table,mine);
				if (tempJudge > maxJudge)
				{
						BestSu.first = j;
						BestSu.second = i;
						maxJudge = tempJudge;
						judgementTable[j][i] = tempJudge;
				}
				std::fill(&table[0], &table[TABLEMAX - 1], 0);

				Verify(j, i, mine, table);
				tempJudge = AttackJudgement(j, i, table,mine);
				if ((mine == BLACK&&!IsUnavailable(table))||mine==WHITE)
				{
					if (tempJudge > maxJudge)
					{
						BestSu.first = j;
						BestSu.second = i;
						maxJudge = tempJudge;
						judgementTable[j][i] = tempJudge;
					}
				}
				
			}
		}
	}
	if (BestSu.first == -1)
	{
		while (true)
		{
			int x = rand() % MAX;
			int y = rand() % MAX;
			
			if (basePan[x][y] != mine&&basePan[x][y] != opposite) {
				//Verify(x, y, opposite, table);
				BestSu.first = x;
				BestSu.second = y;
				break;
			}
		}
	}

	return BestSu;
}
int   AttackJudgement(int x, int y, const int* table,char mine)
{
	if (mine == BLACK)
	{
		if (table[4] == 1) { return Result::WIN+1; }
		else if (table[8] >= 1 && table[2] >= 1) { return Result::WIN - 10 + 1; }
		else if (table[3] == 1) { return Result::WIN - 10+1; }
		else if (table[3] == 1) { return Result::FOUR; }
		else if (table[2] == 1) { return Result::THREE + table[1]; }
		else if (table[8] == 1) { return Result::THREE + table[1]; }
		else if (table[1] >= 1) { return table[1]; }
		else
			return 0;
	}
	else
	{
		if (table[4] == 1) { return Result::WIN+1; }
		else if (table[3] > 1) { return Result::WIN - 10+1; }
		else if (table[8] >= 1 && table[2] >= 1) { return Result::WIN - 10+1; }
		else if (table[3] == 1) { return Result::FOUR + 1; }
		else if (table[2] > 1) { return Result::THREE+8; }
		else if (table[2] == 1) { return Result::THREE + table[1]; }
		else if (table[8] == 1) { return Result::THREE + table[1]; }
		else if (table[1] >= 1) { return table[1]; }
		else
			return 0;
	}
}
int  DefenceJudgement(int x, int y, const int* table,char mine)
{
	if (mine == WHITE)
	{
		if (table[4] == 1) { return Result::WIN; }
		//else if (table[8] >= 1 && table[2] >= 1) { return Result::WIN - 10; }
		else if (table[3] == 1) { return Result::FOUR; }
		else if (table[2] == 1) { return Result::THREE + table[1] + 1; }
		else if (table[8] == 1) { return Result::THREE + table[1]+1; }
		else if (table[1] >= 1) { return table[1]+1; }
		else
			return 0;
	}
	else
	{
		
		if (table[4] == 1) { return Result::WIN; }
		//else if (table[8] == 1 && table[2] == 1) { return Result::WIN - 10; }
		else if (table[3] > 1) { return Result::WIN - 20; }
		else if (table[3] == 1) { return Result::FOUR + table[1]; }
		else if (table[2] > 1) { return Result::THREE+8+1; }
		else if (table[2] == 1) { return Result::THREE + table[1]+1; }
		else if (table[8] == 1) { return Result::THREE + table[1]; }
		else if (table[1] >= 1) { return table[1]+1; }
		else
			return 0;
	}
}

void BlockSituation(int v, int* table)
{
	if (v - 100 == 3)
		++table[8];
	if (v - 100 == 4)
		++table[4];
	else if (v - 200 == 4)
		++table[4];
	else if (v %100== 5)
		++table[5];
	else if (v > 200)
		return;
	else if ((v % 100) - 2>0)
		++table[v % 100 - 1];
}
int  CountStone(const int x, const int y, const char stone, const Direction d, bool firstBlank = true, int count = 0)
{

	if (x == -1 || y == -1) { return 0; }
	if (x >= MAX || y >= MAX) { return 0; }


	if (count == 0)
	{
		if (firstBlank&&basePan[x][y] == COMMON)
		{
			if (basePan[x + moving[d].first][y + moving[d].second]==stone&&basePan[x + (moving[d].first*2)][y + (moving[d].second*2)] == stone&&basePan[x + (moving[d].first * 3)][y + (moving[d].second * 3)] == stone&&basePan[x + (moving[d].first * 3)][y + (moving[d].second * 3)] !=stone)
			{
				return 3;
			}
			else if (basePan[x + moving[d].first][y + moving[d].second] == stone&&basePan[x + (moving[d].first * 2)][y + (moving[d].second * 2)] == stone&&basePan[x + (moving[d].first * 3)][y + (moving[d].second * 3)] != stone)
			{
				return 2;
			}
			else if (basePan[x + moving[d].first][y + moving[d].second] == stone&&basePan[x + (moving[d].first * 2)][y + (moving[d].second * 2)] != stone)
			{
				return 1;
			}
			else
				return 0;
		}
		else if (basePan[x][y] == COMMON)
			return 0;
		else if (basePan[x][y] != stone&&basePan[x][y] != COMMON)
			return 100;
		else
			return 1 + CountStone(x + moving[d].first, y + moving[d].second, stone, d, firstBlank, ++count);
	}
	if (count>=1)
	{
		if (basePan[x][y] == COMMON)
		{
			return 0;
		}
		else if (basePan[x][y] != stone&&basePan[x][y] != COMMON)
		{
			return 100;
		}
		else {
			return 1 + CountStone(x + moving[d].first, y + moving[d].second, stone, d, firstBlank, ++count);
		}

	}
	//else if(count==1){
	//	if (firstBlank&&basePan[x][y] == COMMON)
	//		return CountStone(x + moving[d].first, y + moving[d].second, stone, d, false, ++count);
	//	else if (basePan[x][y] == COMMON)
	//		return 0;
	//	else if (basePan[x][y] != stone&&basePan[x][y] != COMMON)
	//		return 100;
	//	else
	//		return 1 + CountStone(x + moving[d].first, y + moving[d].second, stone, d, firstBlank, ++count);
	//}

}



bool  IsUnavailable(const int* table)
{
	if (table[5] >= 1)
	{
		return true;
	}
	if (table[2] >= 2)
		return true;
	if (table[3] >= 2)
		return true;
	
	return false;
}
void BlankSituation(int v, int* table)
{
	if (v - 777 == 3)
		table[3]++;
	else
		table[0]++;
}

void  Verify(const int& i, const int& j, const char& stone, int* table)
{
	int v = 0;
	//if(table[1]>0)
	//cout << "--------------------------------------------------first : "<<table[1]<<" "<<i<<" "<<j << endl;
	v = CountStone(i + moving[Direction::N].first, j + moving[Direction::N].second, stone, Direction::N) 
		+ CountStone(i + moving[Direction::S].first, j + moving[Direction::S].second, stone, Direction::S);

	v<100 ? ++table[v]: BlockSituation(v, table);
	v = CountStone(i + moving[Direction::E].first, j + moving[Direction::E].second, stone, Direction::E) + CountStone(i + moving[Direction::W].first, j + moving[Direction::W].second, stone, Direction::W);
	v<100 ? ++table[v]  : BlockSituation(v, table);
	//if (table[1]>0)
	//cout << "--------------------------------------------------second: " << table[1] << endl;
	v = CountStone(i + moving[Direction::NE].first, j + moving[Direction::NE].second, stone, Direction::NE) + CountStone(i + moving[Direction::SW].first, j + moving[Direction::SW].second, stone, Direction::SW);
	v<100 ? ++table[v]  : BlockSituation(v, table);
	v = CountStone(i + moving[Direction::SE].first, j + moving[Direction::SE].second, stone, Direction::SE) + CountStone(i + moving[Direction::NW].first, j + moving[Direction::NW].second, stone, Direction::NW);
	v<100 ? ++table[v]: BlockSituation(v, table);

}

int main()
{
	Judgment mainGame;
	mainGame.SetYourFunc(&BlackAttack_2013184043, &BlackDefence_2013184043, &WhiteAttack_2013180016, &WhiteDefence_2013180016);
	mainGame.GamePlay();
}