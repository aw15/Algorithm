#pragma once

#include "Judgment.h"
#include <time.h>
#define SIZE_2016182043 19


struct Point_2016182043 {
	int x, y;
};

int board_2016182043[SIZE_2016182043 + 2][SIZE_2016182043 + 2];
int nBoard_2016182043[SIZE_2016182043 + 2][SIZE_2016182043 + 2];
int nWeight_2016182043[SIZE_2016182043 + 2][SIZE_2016182043 + 2];
enum { empty_2016182043, black_2016182043, white_2016182043, wall_2016182043 };
bool first_2016182043 = true;
bool isOpenFour_2016182043;
Point_2016182043      l_2016182043, r_2016182043; //left top, right bottom;
int X_2016182043, Y_2016182043;

void rule_GetDirTable_2016182043(int &x, int &y, int nDir);
bool rule_IsEmpty_2016182043(int &x, int &y, int nStone, int nDir);
int GetStoneCount_2016182043(int x, int y, int nStone, int nDir);
bool rule_IsFive_2016182043(int x, int y, int nStone);
bool rule_IsFive_2016182043(int x, int y, int nStone, int nDir);
bool rule_IsSix_2016182043(int x, int y, int nStone);
bool rule_IsFour_2016182043(int x, int y, int nStone, int nDir);
int rule_IsOpenFour_2016182043(int x, int y, int nStone, int nDir);
bool rule_IsDoubleFour_2016182043(int x, int y, int nStone);
bool rule_IsOpenThree_2016182043(int x, int y, int nStone, int nDir);
bool rule_IsDoubleThree_2016182043(int x, int y, int nStone);
bool rule_IsForbidden_2016182043(int x, int y, int nStone);
void initWeight_2016182043();
bool IsEmpty_2016182043(int x, int y, int nStone);
void GetRect_2016182043(Point_2016182043 &p1, Point_2016182043 &p2);
void setRect_2016182043();
int IsThree_2016182043(int x, int y, int nStone, int nDir);
int IsOpenThree_2016182043(int x, int y, int nStone, int nDir);
int IsOpenTwo_2016182043(int x, int y, int nStone, int nDir);
int IsTwo_2016182043(int x, int y, int nStone, int nDir);
int IsFour_2016182043(int x, int y, int nStone, int nDir);
bool IsFourThree_2016182043(int x, int y, int nStone);
bool IsDoubleFour_2016182043(int x, int y, int nStone);
int IsOpenFour_2016182043(int x, int y, int nStone, int nDir);
int yourOpenFour_2016182043(int x, int y, int nStone, int nDir);
bool IsFive_2016182043(int x, int y, int nStone);
bool IsSix_2016182043(int x, int y, int nStone);
void fillWeight_2016182043(int myStone, bool isRenju);
bool findPutPoint_2016182043(int &x, int &y, int nStone, bool(*fp)(int, int, int));
void findPutOnPoint_2016182043(int &x, int &y, int nStone);
void renju_findPutOnPoint_2016182043(int &x, int &y, int nStone);


// 8개의 숫자는 8방향을 나타낸다.
// 배열의 순서대로 서, 동, 북, 남, 서북, 동남, 남서, 북동
// (동, 서) (남 북) (서북, 동남) (남서, 북동)이 한쌍이되어
// 가로 세로 양 대각선의 양쪽을 dx, dy로 표시한 Table 
void rule_GetDirTable_2016182043(int &x, int &y, int nDir)
{
	//          서  동  북  남  북서 남동 남서 북동 
	int dx[] = { -1,  1,  0,  0, -1,   1,  -1,   1 };
	int dy[] = { 0,  0, -1,  1, -1,   1,   1,  -1 };

	x = dx[nDir];
	y = dy[nDir];
}

// 주어진 방향으로 좌표를 옮겨 빈곳을 찾아 
// 그곳의 좌료를 알려준다. 
bool rule_IsEmpty_2016182043(int &x, int &y, int nStone, int nDir)
{
	int dx, dy;

	// 방향 Table에서 dx, dy값을 가져온다.
	// 만약 nDir이 0이라면 dx = -1, dy = 0이다. 
	rule_GetDirTable_2016182043(dx, dy, nDir);
	// x는 1 y는 0이니까 x += dx, y += dy 이 수식에 의해서 
	// x는 점점 작아저 왼쪽으로 가고, y는 변함이 없으니 한자리
	// 그래서 가로로 왼쪽에 nStone이 아닌 곳에서 멈추게 된다. 
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy);

	// nStone이 아니라 해서 전부 LINE이라 할 수 없다.
	// 다른 돌이거나 바둑판을 벗어난 곳 일수도 있으니
	// 그곳이 LINE일 때만 참을 반환한다. 
	return nBoard_2016182043[y][x] == empty_2016182043;
}

// 주어진 좌표에 한점을 착점하고,
// 주어진 방향(nDir)으로 
// 연속된 돌이 몇개인지 세어서 반환한다. 
int GetStoneCount_2016182043(int x, int y, int nStone, int nDir)
{
	int dx, dy;
	int tx = x;
	int ty = y;
	int cnt = 0;

	// 착점할 곳이 Line이 아니면 착점할 수 없으니
	// 0을 return한다. 
	if (nBoard_2016182043[y][x] != empty_2016182043) return 0;
	nBoard_2016182043[y][x] = nStone;

	// 방향 Table에서 dx, dy값을 가져와 
	rule_GetDirTable_2016182043(dx, dy, nDir);
	//착점한 곳에서부터 nDir방향으로 같은 돌의 갯수를 센다. 
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy) cnt++;

	// 방향 Table이 하나로 되어있고, 
	// 순서는 항상 서동 또는 북남으로 되어 있어 
	// nDir이 홀수일 때는 -1한 방향을 검사하여야 한다.
	// 그렇지 않고 다음 방향이라고 무심코 +1한다면
	// 만약 nDir이 동(1)이라면 서(0)쪽을 검사해야 되는데
	// +1해서 2가 되면 서(0)가 아닌 북(2)을 검사하게 된다. 
	// 이를 방지하기 위해 3항 연산자를 이용해
	// 조건에 맞는 방향을 인수로 넘기게 하였다. 
	rule_GetDirTable_2016182043(dx, dy, nDir % 2 ? nDir - 1 : nDir + 1);

	// x, y값이 위에서 연산을 하느라 처음 좌표를 벗어났기 때문에
	// 처음 좌표값에 다음 방향으로 한칸 옮겨서 그곳에서부터
	// 돌의 갯수를 센다. 
	// 위에서 돌 놓았던 곳을 세었기에 중복을 피하기 위해서다. 
	x = tx + dx;
	y = ty + dy;
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy) cnt++;

	// 돌의 갯수를 다 세었으면 돌을 들어낸다. 
	nBoard_2016182043[ty][tx] = empty_2016182043;
	return cnt;
}

// 착점을 하였을때 오목인지 검사한다. 
bool rule_IsFive_2016182043(int x, int y, int nStone)
{
	// 방향 Table의 값이 8이니까 8까지 검사하고
	// 증가분이 +=2인건
	// 아래 GetStoneCount_2016182043()함수 안에서 양끝을 검사하기 때문이다. 
	for (int i = 0; i < 8; i += 2) {
		if (GetStoneCount_2016182043(x, y, nStone, i) == 5) return true;
	}
	return false;
}

// 위와 같이 오목인지를 검사하지만,
// nDir방향에 대해서만 검사한다.
// 이는 Four나 OpenFour가 되는지 알아보기 위하여 
// 빈곳에 돌을 하나씩 놓아보면서
// 오목이 되는지 검사하기 위해서다. 
bool rule_IsFive_2016182043(int x, int y, int nStone, int nDir)
{
	if (GetStoneCount_2016182043(x, y, nStone, nDir) == 5) return true;
	return false;
}

// 오목을 검사하는 것과 같이 6목 이상인지 검사한다. 
bool rule_IsSix_2016182043(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2) {
		if (GetStoneCount_2016182043(x, y, nStone, i) >= 6) return true;
	}
	return false;
}

// 착수를 했을때 4인지를 검사한다. 
bool rule_IsFour_2016182043(int x, int y, int nStone, int nDir)
{
	// 원래의 좌표 x, y를 대신하기 위한 변수 
	int tx, ty;

	// 한 방향에 대하여 양끝을 검사하는데
	// 한쌍의 좌표중 첫번째부터 검사하기 위하여 
	nDir % 2 ? nDir -= 1 : nDir;
	// 좌표에 착점을 한다 
	nBoard_2016182043[y][x] = nStone;
	// 다음 양끝을 검사 
	for (int i = 0; i < 2; i++) {
		// 원래의 좌표를 중심으로 주어진 방향(nDir)에 대하여
		// 양쪽으로 이동하면서 빈곳을 찾아 그곳의 좌표를 얻어와야 되기에
		// 원래의 좌표가 변경이 된다. 따라서 양쪽을 검사하기위하여
		// 대신할 변수가 필요하고, 매번 아래와 같이 
		// 원래의 좌표를 받아서 검사가 진행되어야 한다. 
		tx = x;
		ty = y;
		// 빈곳이 있으면 그 좌표를 받아온다. 
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			// 그 빈곳에서 오목이 되는지 검사한다. 
			if (rule_IsFive_2016182043(tx, ty, nStone, nDir + i)) {
				// 오목이 되었다면 4이기 때문에 
				// 돌을 들어내고 참을 리턴한다. 
				nBoard_2016182043[y][x] = empty_2016182043;
				return true;
			}
		}
	}

	// 검사를 해봤지만 4가 아니라 해도 돌을 들어낸다. 
	nBoard_2016182043[y][x] = empty_2016182043;
	return false;
}

// 돌이 연속으로 4개이고 끝에 돌을 놓았을때 오목이 되면 
// 열린4가 된다. 
int rule_IsOpenFour_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	// 열린4가 될때는 양쪽에 돌을 놓았을때 
	// 양쪽 모두 오목이 되어야 되기때문에
	// 두곳다 4가 되는지 검사를 위한 변수 
	int sum = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		// 여기까지는 Four()함수와 같다. 
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (rule_IsFive_2016182043(tx, ty, nStone, nDir + i)) sum++;
		}
	}
	nBoard_2016182043[y][x] = empty_2016182043;

	// 양쪽으로 모두가 오목이 되었을때만 열린4이다. 
	if (sum == 2) {
		// 열린4일 때는 특이하게 한줄에 44가 될수 있다.
		// 1234567   12345678
		// 0 0 0 0   00  0 00
		// 위와 같은 상황에서 4위치에 돌이 놓이면
		// 양쪽이 모두 4가 되어 한줄에서 44가 발생한다.
		// 때문에 0000 이와같이 연속일때는 4가 하나이기 때문에
		// 검사를 하여 갯수를 정확하게 한다. 
		if (GetStoneCount_2016182043(x, y, nStone, nDir) == 4) sum = 1;
	}
	// sum이 2가 아니면 열린4가 아니므로 0 
	else sum = 0;

	return sum;
}

bool rule_IsDoubleFour_2016182043(int x, int y, int nStone)
{
	int cnt = 0;

	//좌표를 중심으로 각각의 줄에대하여 4를 검사한다. 
	for (int i = 0; i < 8; i += 2) {
		// OpenFour()에서는 한 줄에 44가 나올 수 있으니 검사하고 
		if (IsOpenFour_2016182043(x, y, nStone, i) == 2) return true;
		// 열린4도 4이니 4를 검사하여 2개 이상이면 44이다. 
		else if (IsFour_2016182043(x, y, nStone, i)) cnt++;

		if (cnt >= 2) return true;
	}

	return false;
}

bool rule_IsOpenThree_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			// 33은 돌을 하나 더 놓았을 때 반드시 열린4이어야 되고, 
			// 한 점 놓을 자리가 44, 6목, 또다른 33 
			// 즉 금수자리가 아니어야 된다.
			if ((rule_IsOpenFour_2016182043(tx, ty, nStone, nDir) == 1) && (!rule_IsForbidden_2016182043(tx, ty, nStone))) {
				// 위 조건을 만족하는 자리이면 3이므로 돌을 제거하고 참을 리턴한다. 
				nBoard_2016182043[y][x] = empty_2016182043;
				return true;
			}
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return false;
}

// 33을 검사한다. 
bool rule_IsDoubleThree_2016182043(int x, int y, int nStone)
{
	int cnt = 0;

	for (int i = 0; i < 8; i += 2) {
		if (rule_IsOpenThree_2016182043(x, y, nStone, i)) cnt++;
		if (cnt >= 2) return true;
	}

	return false;
}

// 금수자리를 검사한다. 
bool rule_IsForbidden_2016182043(int x, int y, int nStone)
{
	if (rule_IsDoubleFour_2016182043(x, y, nStone)) return true;
	else if (rule_IsDoubleThree_2016182043(x, y, nStone)) return true;
	else if (rule_IsSix_2016182043(x, y, nStone)) return true;
	else return false;
}









void initWeight_2016182043()
{
	for (int i = 1; i <= SIZE_2016182043; i++) {
		for (int j = 0; j <= SIZE_2016182043; j++) {
			nWeight_2016182043[i][j] = 0;
		}
	}
}

bool IsEmpty_2016182043(int x, int y, int nStone)
{
	return nBoard_2016182043[y][x] == empty_2016182043;
}

void GetRect_2016182043(Point_2016182043 &p1, Point_2016182043 &p2)
{
	p1.x = p1.y = SIZE_2016182043;
	p2.x = p2.y = 0;
	for (int i = 1; i <= SIZE_2016182043; i++) {
		for (int j = 0; j <= SIZE_2016182043; j++) {
			if (nBoard_2016182043[i][j] == black_2016182043 || nBoard_2016182043[i][j] == white_2016182043) {
				if (p1.x > j) p1.x = j;
				if (p2.x < j) p2.x = j;
				if (p1.y > i) p1.y = i;
				if (p2.y < i) p2.y = i;
			}
		}
	}
}

void setRect_2016182043()
{
	GetRect_2016182043(l_2016182043, r_2016182043);

	l_2016182043.x -= 2; if (l_2016182043.x < 1) l_2016182043.x = 1;
	l_2016182043.y -= 2; if (l_2016182043.y < 1) l_2016182043.y = 1;
	r_2016182043.x += 2; if (r_2016182043.x > SIZE_2016182043) r_2016182043.x = SIZE_2016182043;
	r_2016182043.y += 2; if (r_2016182043.y > SIZE_2016182043) r_2016182043.y = SIZE_2016182043;
}

int IsThree_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	int cnt = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (rule_IsFour_2016182043(tx, ty, nStone, nDir))
				if (rule_IsOpenFour_2016182043(tx, ty, nStone, nDir) == 0) cnt++;
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return cnt;
}

int IsOpenThree_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	int cnt = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (rule_IsOpenFour_2016182043(tx, ty, nStone, nDir) == 1) cnt++;
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return cnt;
}

int IsOpenTwo_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	int cnt = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (IsOpenThree_2016182043(tx, ty, nStone, nDir) == 2) cnt++;
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return cnt;
}

int IsTwo_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	int cnt = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (IsThree_2016182043(tx, ty, nStone, nDir) == 1) cnt++;
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return cnt;
}

int IsFour_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	int cnt = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	for (int i = 0; i < 2; i++) {
		if (rule_IsFour_2016182043(x, y, nStone, nDir + i))
			if (rule_IsOpenFour_2016182043(x, y, nStone, nDir) == 0) cnt++;
	}
	return cnt;
}

bool IsFourThree_2016182043(int x, int y, int nStone)
{
	int fCnt = 0;
	int tCnt = 0;

	for (int i = 0; i < 8; i += 2) {
		if (rule_IsFour_2016182043(x, y, nStone, i)) fCnt++;
		else if (tCnt = IsOpenThree_2016182043(x, y, nStone, i));

		if (fCnt && tCnt) return true;
	}

	return false;
}


bool IsDoubleFour_2016182043(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2) {
		if (rule_IsDoubleFour_2016182043(x, y, nStone)) return true;
	}
	return false;
}

int IsOpenFour_2016182043(int x, int y, int nStone, int nDir)
{
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		if (rule_IsOpenFour_2016182043(x, y, nStone, nDir + 1) == 1) cnt++;
	}
	return cnt;
}

int yourOpenFour_2016182043(int x, int y, int nStone, int nDir)
{
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		if (IsOpenFour_2016182043(x, y, nStone, nDir)) cnt++;
	}
	return cnt;
}

bool IsFive_2016182043(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2) {
		if (rule_IsFive_2016182043(x, y, nStone)) return true;
	}
	return false;
}

bool IsSix_2016182043(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2) {
		if (rule_IsSix_2016182043(x, y, nStone)) return true;
	}
	return false;
}

void fillWeight_2016182043(int myStone, bool isRenju)
{
	int cnt;
	int yourStone = (myStone + 1) % 2;

	// 아래 함수의 순서대로 점수를 정하여 봤다. 
	// 점수가 높은 곳에 착점을 하는 알고리즘이라
	// 한 수 앞을 보지 못하고 최선의 수만 둘뿐이다. 
	int arrWeight[] = { 2, 5, 10, 30, 35, 300 };
	//int (COMOKAI::*fp[6])(int, int, int, int) = { IsTwo_2016182043, IsOpenTwo_2016182043, IsThree_2016182043, IsOpenThree_2016182043, IsFour_2016182043, yourOpenFour_2016182043 };

	// 복잡하여 전체적으로 손질이 필요해서 
	// 차후 개선이 되면 그때 설명을 첨부하겠슴.
	// OpenFour의 경우 상대의 돌과 내돌 모두 삼이 있을 경우
	// 내돌에 우선권을 주려고 점수를 달리 해봤슴.

	// 열린4가 있는데도 상대의 43자리가 있으면 그곳 부터 막아서 
	// 렌주룰에서 백은 6목을 둘 수 있기 때문에 6목될 수 있는 
	// OpenFour를 막지 못하여 간단하게 수정해보려 했지만 실패
	// 차후 점수 시스템과 여러가지를 손봐야 할 곳 
	isOpenFour_2016182043 = false;
	for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
		for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
			for (int f = 0; f < 6; f++) {
				if (!IsEmpty_2016182043(j, i, myStone)) continue;
				cnt = 0;
				arrWeight[5] = 300;
				for (int n = 0; n < 8; n += 2) {
					if (f == 5 && isRenju) cnt = IsOpenFour_2016182043(j, i, myStone, n);
					else cnt = IsOpenFour_2016182043(j, i, myStone, n);
					switch (f) {
					case 0:
						cnt = IsTwo_2016182043(j, i, myStone, n);
						break;
					case 1:
						cnt = IsOpenTwo_2016182043(j, i, myStone, n);
						break;
					case 2:
						cnt = IsThree_2016182043(j, i, myStone, n);
						break;
					case 3:
						cnt = IsOpenThree_2016182043(j, i, myStone, n);
						break;
					case 4:
						cnt = IsFour_2016182043(j, i, myStone, n);
						break;
					case 5:
						cnt = yourOpenFour_2016182043(j, i, myStone, n);
						break;
					}
					if (f == 5) {
						if (cnt) isOpenFour_2016182043 = true;
						else arrWeight[5] = 100;
					}
					switch (f) {
					case 0:
						cnt += IsTwo_2016182043(j, i, yourStone, n);
						break;
					case 1:
						cnt += IsOpenTwo_2016182043(j, i, yourStone, n);
						break;
					case 2:
						cnt += IsThree_2016182043(j, i, yourStone, n);
						break;
					case 3:
						cnt += IsOpenThree_2016182043(j, i, yourStone, n);
						break;
					case 4:
						cnt += IsFour_2016182043(j, i, yourStone, n);
						break;
					case 5:
						cnt += yourOpenFour_2016182043(j, i, yourStone, n);
						break;
					}
					nWeight_2016182043[i][j] += cnt * arrWeight[f];
				}
			}
		}
	}
}

bool findPutPoint_2016182043(int &x, int &y, int nStone, bool(*fp)(int, int, int))
{
	for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
		for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
			if (!IsEmpty_2016182043(j, i, nStone)) continue;
			if ((*fp)(j, i, nStone)) {
				x = j;
				y = i;
				return true;
			}
		}
	}
	return false;
}

void findPutOnPoint_2016182043(int &x, int &y, int nStone)
{
	int max = -1;
	for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
		for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
			if (!IsEmpty_2016182043(j, i, nStone)) continue;
			if (max < nWeight_2016182043[i][j]) {
				x = j;
				y = i;
				max = nWeight_2016182043[i][j];
			}
		}
	}
}


void renju_findPutOnPoint_2016182043(int &x, int &y, int nStone)
{
	int max = -1;
	for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
		for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
			if (!IsEmpty_2016182043(j, i, nStone)) continue;
			if (rule_IsForbidden_2016182043(j, i, nStone)) continue;
			if (max < nWeight_2016182043[i][j]) {
				x = j;
				y = i;
				max = nWeight_2016182043[i][j];
			}
		}
	}
}



void BlackAttack_2016182043(int *returnx, int*returny)
{
	if (first_2016182043) {
		for (int i = 0; i < SIZE_2016182043 + 2; i++) {
			nBoard_2016182043[i][0] = nBoard_2016182043[i][SIZE_2016182043 + 1] = wall_2016182043;
			nBoard_2016182043[0][i] = nBoard_2016182043[SIZE_2016182043 + 1][i] = wall_2016182043;
		}

		board_2016182043[(SIZE_2016182043 + 2) / 2][(SIZE_2016182043 + 2) / 2] = black_2016182043;

		*returnx = (SIZE_2016182043 + 2) / 2 - 1;
		*returny = (SIZE_2016182043 + 2) / 2 - 1;
		first_2016182043 = false;
	}
	else {
		GetRect_2016182043(l_2016182043, r_2016182043);
		setRect_2016182043();
		initWeight_2016182043();
		fillWeight_2016182043(black_2016182043, true);
		for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
			for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
				if (!IsEmpty_2016182043(j, i, black_2016182043)) continue;
				if (findPutPoint_2016182043(j, i, black_2016182043, IsFive_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
				if (findPutPoint_2016182043(j, i, white_2016182043, IsFive_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
				if (findPutPoint_2016182043(j, i, white_2016182043, IsSix_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
				if (findPutPoint_2016182043(j, i, black_2016182043, IsFourThree_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
				//if(isOpenFour_2016182043) break;
				if (findPutPoint_2016182043(j, i, white_2016182043, IsFourThree_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
				if (findPutPoint_2016182043(j, i, white_2016182043, IsDoubleFour_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			}
		}
		renju_findPutOnPoint_2016182043(X_2016182043, Y_2016182043, black_2016182043);

		while (1) {
			srand((unsigned)time(NULL));
			if (board_2016182043[Y_2016182043][X_2016182043] != empty_2016182043 || X_2016182043 < 1 || X_2016182043>19 || Y_2016182043 < 1 || Y_2016182043>19) {
				X_2016182043 = rand() % (SIZE_2016182043)+1;
				Y_2016182043 = rand() % (SIZE_2016182043)+1;
			}
			else
				break;
		}
		board_2016182043[Y_2016182043][X_2016182043] = black_2016182043;

		*returnx = X_2016182043-1;
		*returny = Y_2016182043-1;
	}
}
void BlackDefence_2016182043(int x, int y)
{
	board_2016182043[y + 1][x + 1] = white_2016182043;
	X_2016182043 = x;
	Y_2016182043 = y;
}
void WhiteAttack_2016182043(int *returnx, int *returny)
{
	for (int i = 0; i < SIZE_2016182043 + 2; i++) {
		nBoard_2016182043[i][0] = nBoard_2016182043[i][SIZE_2016182043 + 1] = wall_2016182043;
		nBoard_2016182043[0][i] = nBoard_2016182043[SIZE_2016182043 + 1][i] = wall_2016182043;
	}
	initWeight_2016182043();
	GetRect_2016182043(l_2016182043, r_2016182043);
	setRect_2016182043();
	fillWeight_2016182043(white_2016182043, false);
	for (int i = l_2016182043.y; i <= r_2016182043.y; i++) {
		for (int j = l_2016182043.x; j <= r_2016182043.x; j++) {
			if (!IsEmpty_2016182043(j, i, white_2016182043)) continue;
			if (findPutPoint_2016182043(j, i, white_2016182043, IsFive_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, white_2016182043, IsSix_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, black_2016182043, IsFive_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, black_2016182043, IsSix_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, white_2016182043, IsFourThree_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, white_2016182043, IsDoubleFour_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			//if(isOpenFour_2016182043) break;
			if (findPutPoint_2016182043(j, i, black_2016182043, IsFourThree_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
			if (findPutPoint_2016182043(j, i, black_2016182043, IsDoubleFour_2016182043)) { X_2016182043 = j; Y_2016182043 = i; return; }
		}
	}

	findPutOnPoint_2016182043(X_2016182043, Y_2016182043, white_2016182043);


	while (1) {
	srand((unsigned)time(NULL));
		if (board_2016182043[Y_2016182043][X_2016182043] != empty_2016182043 || X_2016182043 < 1 || X_2016182043>19 || Y_2016182043 < 1 || Y_2016182043>19) {
			X_2016182043 = rand() % (SIZE_2016182043)+1;
			Y_2016182043 = rand() % (SIZE_2016182043)+1;
		}
		else
			break;
	}


	board_2016182043[Y_2016182043][X_2016182043] = white_2016182043;

	*returnx = X_2016182043-1;
	*returny = Y_2016182043-1;
}
void WhiteDefence_2016182043(int x, int y)
{
	board_2016182043[y + 1][x + 1] = black_2016182043;
	X_2016182043 = x;
	Y_2016182043 = y;
}