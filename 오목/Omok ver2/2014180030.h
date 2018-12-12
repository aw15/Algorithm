#pragma once
#define YYS 8 
#define Enemy 9
#define MapSize 18

int map[MapSize][MapSize] = { 0 };
int Firstpoint1(int board[][18]) {

	int xpos, ypos;
	int i = 0;
	int jcount;
	int count = 1;
	int tempPlayer = 0;
	//--------------- ����ġ 1 ���� -----------------------------
	for (xpos = 0; xpos<MapSize; xpos++) {
		for (ypos = 0; ypos<MapSize; ypos++) {
			if (ypos < MapSize && board[xpos][ypos + 1] == Enemy && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (ypos > 0 && board[xpos][ypos - 1] == Enemy  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (xpos < MapSize && board[xpos + 1][ypos] == Enemy && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (xpos > 0 && board[xpos - 1][ypos] == Enemy && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos < MapSize && ypos < MapSize) && board[xpos + 1][ypos + 1] == Enemy  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos > 0 && ypos > 0) && board[xpos - 1][ypos - 1] == Enemy  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos > 0 && ypos < MapSize) && board[xpos - 1][ypos + 1] == Enemy  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos < MapSize && ypos > 0) && board[xpos + 1][ypos - 1] == Enemy  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
		}
	}
	//-------------- ���� ������ ���� �Ϲ� ����ġ -------------------

	for (xpos = 0; xpos<MapSize; xpos++) {
		for (ypos = 0; ypos<MapSize; ypos++) {
			if (ypos < MapSize&& board[xpos][ypos] < Enemy&& board[xpos][ypos + 1] >= Enemy)
			{
				count = 0;
				tempPlayer = board[xpos][ypos + 1];
				for (i = ypos + 1; i<MapSize; i++) {
					if (board[xpos][i] == tempPlayer)
						count++;
					else
						break;
				}

				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (ypos > 0
				&& board[xpos][ypos] < Enemy       //���� ����ġ�� ������ ��ġ
				&& board[xpos][ypos - 1] >= Enemy) {   //left�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos][ypos - 1];
				for (i = ypos - 1; i >= 0; i--) {
					if (board[xpos][i] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (xpos < MapSize
				&& board[xpos][ypos] < Enemy          //���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos] >= Enemy) {      //down�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos + 1][ypos];

				for (i = xpos + 1; i<MapSize; i++) {
					if (board[i][ypos] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (xpos > 0
				&& board[xpos][ypos] < Enemy       //���� ����ġ�� ������ ��ġ
				&&  board[xpos - 1][ypos] >= Enemy) {   //up�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos - 1][ypos];
				for (i = xpos - 1; i >= 0; i--) {
					if (board[i][ypos] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos < MapSize && ypos < MapSize)
				&& board[xpos][ypos] < Enemy       // ���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos + 1] >= Enemy)   // right-down�� ���� �ִ� ���
			{
				count = 0;
				tempPlayer = board[xpos + 1][ypos + 1];
				for (i = 1; i<5; i++) {
					if ((xpos + i<MapSize && ypos + i<MapSize) && (board[xpos + i][ypos + i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos > 0 && ypos > 0)
				&& board[xpos][ypos] < Enemy       // ���� ����ġ�� ������ ��ġ
				&& board[xpos - 1][ypos - 1] >= Enemy) { // left-up�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos - 1][ypos - 1];
				for (i = 1; i<5; i++) {
					if ((xpos - i >= 0 && ypos - i >= 0) && (board[xpos - i][ypos - i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos > 0 && ypos < MapSize)
				&& board[xpos][ypos] < Enemy          // ���� ����ġ�� ������ ��ġ
				&& board[xpos - 1][ypos + 1] >= Enemy)      // right-up�� ���� �ִ� ���
			{
				count = 0;
				tempPlayer = board[xpos - 1][ypos + 1];
				for (i = 1; i<10; i++) {
					if ((xpos - i >= 0 && ypos + i<MapSize) && (board[xpos - i][ypos + i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos < MapSize && ypos > 0)
				&& board[xpos][ypos] < Enemy         // ���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos - 1] >= Enemy)  // left-down�� ���� ���� ���
			{
				count = 0;
				tempPlayer = board[xpos + 1][ypos - 1];
				for (i = 1; i<5; i++) {
					if ((xpos + i<MapSize && ypos - i>0) && (board[xpos + i][ypos - i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
		}
	}
	return 0;
}


int Firstpoint2(int board[][18]) {

	int xpos, ypos;
	int i = 0;
	int jcount;
	int count = 1;
	int tempPlayer = 0;
	//--------------- ����ġ 1 ���� -----------------------------
	for (xpos = 0; xpos<MapSize; xpos++) {
		for (ypos = 0; ypos<MapSize; ypos++) {
			if (ypos < MapSize && board[xpos][ypos + 1] == YYS && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (ypos > 0 && board[xpos][ypos - 1] == YYS  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (xpos < MapSize && board[xpos + 1][ypos] == YYS && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if (xpos > 0 && board[xpos - 1][ypos] == YYS && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos < MapSize && ypos < MapSize) && board[xpos + 1][ypos + 1] == YYS  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos > 0 && ypos > 0) && board[xpos - 1][ypos - 1] == YYS  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos > 0 && ypos < MapSize) && board[xpos - 1][ypos + 1] == YYS  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
			else if ((xpos < MapSize && ypos > 0) && board[xpos + 1][ypos - 1] == YYS  && board[xpos][ypos]<1)
				board[xpos][ypos] = 1;
		}
	}
	//-------------- ���� ������ ���� �Ϲ� ����ġ -------------------

	for (xpos = 0; xpos<MapSize; xpos++) {
		for (ypos = 0; ypos<MapSize; ypos++) {
			if (ypos < MapSize&& board[xpos][ypos] < YYS&& board[xpos][ypos + 1] >= YYS)
			{
				count = 0;
				tempPlayer = board[xpos][ypos + 1];
				for (i = ypos + 1; i<MapSize; i++) {
					if (board[xpos][i] == tempPlayer)
						count++;
					else
						break;
				}

				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (ypos > 0
				&& board[xpos][ypos] < YYS       //���� ����ġ�� ������ ��ġ
				&& board[xpos][ypos - 1] >= YYS) {   //left�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos][ypos - 1];
				for (i = ypos - 1; i >= 0; i--) {
					if (board[xpos][i] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (xpos < MapSize
				&& board[xpos][ypos] < YYS          //���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos] >= YYS) {      //down�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos + 1][ypos];

				for (i = xpos + 1; i<MapSize; i++) {
					if (board[i][ypos] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if (xpos > 0
				&& board[xpos][ypos] < YYS       //���� ����ġ�� ������ ��ġ
				&&  board[xpos - 1][ypos] >= YYS) {   //up�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos - 1][ypos];
				for (i = xpos - 1; i >= 0; i--) {
					if (board[i][ypos] == tempPlayer)
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos < MapSize && ypos < MapSize)
				&& board[xpos][ypos] < YYS       // ���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos + 1] >= YYS)   // right-down�� ���� �ִ� ���
			{
				count = 0;
				tempPlayer = board[xpos + 1][ypos + 1];
				for (i = 1; i<5; i++) {
					if ((xpos + i<MapSize && ypos + i<MapSize) && (board[xpos + i][ypos + i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos > 0 && ypos > 0)
				&& board[xpos][ypos] < YYS       // ���� ����ġ�� ������ ��ġ
				&& board[xpos - 1][ypos - 1] >= YYS) { // left-up�� ���� �ִ� ���
				count = 0;
				tempPlayer = board[xpos - 1][ypos - 1];
				for (i = 1; i<5; i++) {
					if ((xpos - i >= 0 && ypos - i >= 0) && (board[xpos - i][ypos - i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos > 0 && ypos < MapSize)
				&& board[xpos][ypos] < YYS          // ���� ����ġ�� ������ ��ġ
				&& board[xpos - 1][ypos + 1] >= YYS)      // right-up�� ���� �ִ� ���
			{
				count = 0;
				tempPlayer = board[xpos - 1][ypos + 1];
				for (i = 1; i<10; i++) {
					if ((xpos - i >= 0 && ypos + i<MapSize) && (board[xpos - i][ypos + i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
			if ((xpos < MapSize && ypos > 0)
				&& board[xpos][ypos] < YYS         // ���� ����ġ�� ������ ��ġ
				&& board[xpos + 1][ypos - 1] >= YYS)  // left-down�� ���� ���� ���
			{
				count = 0;
				tempPlayer = board[xpos + 1][ypos - 1];
				for (i = 1; i<5; i++) {
					if ((xpos + i<MapSize && ypos - i>0) && (board[xpos + i][ypos - i] == tempPlayer))
						count++;
					else
						break;
				}
				if (board[xpos][ypos] < count) {   // �ش� ��ġ ����ġ�� count ���� �۴ٸ�
					board[xpos][ypos] = count;
				}
			}
		}
	}
	return 0;
}




void attack2014180030(int *x, int *y)
{
	int cx = 10, cy = 10;
	int Max = 0;
	Firstpoint1(map);
	Firstpoint2(map);
	for (int i = 0; i< MapSize; i++) {
		for (int j = 0; j< MapSize; j++) {
			if (map[i][j] > Max && map[i][j] < YYS) {
				Max = map[i][j];
				cx = i;
				cy = j;
			}
		}
	}
	*x = cx;
	*y = cy;
	map[cx][cy] = YYS;
}

void BlackDefence(int x, int y)
{
	map[x][y] = Enemy;
}