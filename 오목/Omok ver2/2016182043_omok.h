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


// 8���� ���ڴ� 8������ ��Ÿ����.
// �迭�� ������� ��, ��, ��, ��, ����, ����, ����, �ϵ�
// (��, ��) (�� ��) (����, ����) (����, �ϵ�)�� �ѽ��̵Ǿ�
// ���� ���� �� �밢���� ������ dx, dy�� ǥ���� Table 
void rule_GetDirTable_2016182043(int &x, int &y, int nDir)
{
	//          ��  ��  ��  ��  �ϼ� ���� ���� �ϵ� 
	int dx[] = { -1,  1,  0,  0, -1,   1,  -1,   1 };
	int dy[] = { 0,  0, -1,  1, -1,   1,   1,  -1 };

	x = dx[nDir];
	y = dy[nDir];
}

// �־��� �������� ��ǥ�� �Ű� ����� ã�� 
// �װ��� �·Ḧ �˷��ش�. 
bool rule_IsEmpty_2016182043(int &x, int &y, int nStone, int nDir)
{
	int dx, dy;

	// ���� Table���� dx, dy���� �����´�.
	// ���� nDir�� 0�̶�� dx = -1, dy = 0�̴�. 
	rule_GetDirTable_2016182043(dx, dy, nDir);
	// x�� 1 y�� 0�̴ϱ� x += dx, y += dy �� ���Ŀ� ���ؼ� 
	// x�� ���� �۾��� �������� ����, y�� ������ ������ ���ڸ�
	// �׷��� ���η� ���ʿ� nStone�� �ƴ� ������ ���߰� �ȴ�. 
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy);

	// nStone�� �ƴ϶� �ؼ� ���� LINE�̶� �� �� ����.
	// �ٸ� ���̰ų� �ٵ����� ��� �� �ϼ��� ������
	// �װ��� LINE�� ���� ���� ��ȯ�Ѵ�. 
	return nBoard_2016182043[y][x] == empty_2016182043;
}

// �־��� ��ǥ�� ������ �����ϰ�,
// �־��� ����(nDir)���� 
// ���ӵ� ���� ����� ��� ��ȯ�Ѵ�. 
int GetStoneCount_2016182043(int x, int y, int nStone, int nDir)
{
	int dx, dy;
	int tx = x;
	int ty = y;
	int cnt = 0;

	// ������ ���� Line�� �ƴϸ� ������ �� ������
	// 0�� return�Ѵ�. 
	if (nBoard_2016182043[y][x] != empty_2016182043) return 0;
	nBoard_2016182043[y][x] = nStone;

	// ���� Table���� dx, dy���� ������ 
	rule_GetDirTable_2016182043(dx, dy, nDir);
	//������ ���������� nDir�������� ���� ���� ������ ����. 
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy) cnt++;

	// ���� Table�� �ϳ��� �Ǿ��ְ�, 
	// ������ �׻� ���� �Ǵ� �ϳ����� �Ǿ� �־� 
	// nDir�� Ȧ���� ���� -1�� ������ �˻��Ͽ��� �Ѵ�.
	// �׷��� �ʰ� ���� �����̶�� ������ +1�Ѵٸ�
	// ���� nDir�� ��(1)�̶�� ��(0)���� �˻��ؾ� �Ǵµ�
	// +1�ؼ� 2�� �Ǹ� ��(0)�� �ƴ� ��(2)�� �˻��ϰ� �ȴ�. 
	// �̸� �����ϱ� ���� 3�� �����ڸ� �̿���
	// ���ǿ� �´� ������ �μ��� �ѱ�� �Ͽ���. 
	rule_GetDirTable_2016182043(dx, dy, nDir % 2 ? nDir - 1 : nDir + 1);

	// x, y���� ������ ������ �ϴ��� ó�� ��ǥ�� ����� ������
	// ó�� ��ǥ���� ���� �������� ��ĭ �Űܼ� �װ���������
	// ���� ������ ����. 
	// ������ �� ���Ҵ� ���� �����⿡ �ߺ��� ���ϱ� ���ؼ���. 
	x = tx + dx;
	y = ty + dy;
	for (; nBoard_2016182043[y][x] == nStone; x += dx, y += dy) cnt++;

	// ���� ������ �� �������� ���� ����. 
	nBoard_2016182043[ty][tx] = empty_2016182043;
	return cnt;
}

// ������ �Ͽ����� �������� �˻��Ѵ�. 
bool rule_IsFive_2016182043(int x, int y, int nStone)
{
	// ���� Table�� ���� 8�̴ϱ� 8���� �˻��ϰ�
	// �������� +=2�ΰ�
	// �Ʒ� GetStoneCount_2016182043()�Լ� �ȿ��� �糡�� �˻��ϱ� �����̴�. 
	for (int i = 0; i < 8; i += 2) {
		if (GetStoneCount_2016182043(x, y, nStone, i) == 5) return true;
	}
	return false;
}

// ���� ���� ���������� �˻�������,
// nDir���⿡ ���ؼ��� �˻��Ѵ�.
// �̴� Four�� OpenFour�� �Ǵ��� �˾ƺ��� ���Ͽ� 
// ����� ���� �ϳ��� ���ƺ��鼭
// ������ �Ǵ��� �˻��ϱ� ���ؼ���. 
bool rule_IsFive_2016182043(int x, int y, int nStone, int nDir)
{
	if (GetStoneCount_2016182043(x, y, nStone, nDir) == 5) return true;
	return false;
}

// ������ �˻��ϴ� �Ͱ� ���� 6�� �̻����� �˻��Ѵ�. 
bool rule_IsSix_2016182043(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2) {
		if (GetStoneCount_2016182043(x, y, nStone, i) >= 6) return true;
	}
	return false;
}

// ������ ������ 4������ �˻��Ѵ�. 
bool rule_IsFour_2016182043(int x, int y, int nStone, int nDir)
{
	// ������ ��ǥ x, y�� ����ϱ� ���� ���� 
	int tx, ty;

	// �� ���⿡ ���Ͽ� �糡�� �˻��ϴµ�
	// �ѽ��� ��ǥ�� ù��°���� �˻��ϱ� ���Ͽ� 
	nDir % 2 ? nDir -= 1 : nDir;
	// ��ǥ�� ������ �Ѵ� 
	nBoard_2016182043[y][x] = nStone;
	// ���� �糡�� �˻� 
	for (int i = 0; i < 2; i++) {
		// ������ ��ǥ�� �߽����� �־��� ����(nDir)�� ���Ͽ�
		// �������� �̵��ϸ鼭 ����� ã�� �װ��� ��ǥ�� ���;� �Ǳ⿡
		// ������ ��ǥ�� ������ �ȴ�. ���� ������ �˻��ϱ����Ͽ�
		// ����� ������ �ʿ��ϰ�, �Ź� �Ʒ��� ���� 
		// ������ ��ǥ�� �޾Ƽ� �˻簡 ����Ǿ�� �Ѵ�. 
		tx = x;
		ty = y;
		// ����� ������ �� ��ǥ�� �޾ƿ´�. 
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			// �� ������� ������ �Ǵ��� �˻��Ѵ�. 
			if (rule_IsFive_2016182043(tx, ty, nStone, nDir + i)) {
				// ������ �Ǿ��ٸ� 4�̱� ������ 
				// ���� ���� ���� �����Ѵ�. 
				nBoard_2016182043[y][x] = empty_2016182043;
				return true;
			}
		}
	}

	// �˻縦 �غ����� 4�� �ƴ϶� �ص� ���� ����. 
	nBoard_2016182043[y][x] = empty_2016182043;
	return false;
}

// ���� �������� 4���̰� ���� ���� �������� ������ �Ǹ� 
// ����4�� �ȴ�. 
int rule_IsOpenFour_2016182043(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	// ����4�� �ɶ��� ���ʿ� ���� �������� 
	// ���� ��� ������ �Ǿ�� �Ǳ⶧����
	// �ΰ��� 4�� �Ǵ��� �˻縦 ���� ���� 
	int sum = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	nBoard_2016182043[y][x] = nStone;
	for (int i = 0; i < 2; i++) {
		tx = x;
		ty = y;
		// ��������� Four()�Լ��� ����. 
		if (rule_IsEmpty_2016182043(tx, ty, nStone, nDir + i)) {
			if (rule_IsFive_2016182043(tx, ty, nStone, nDir + i)) sum++;
		}
	}
	nBoard_2016182043[y][x] = empty_2016182043;

	// �������� ��ΰ� ������ �Ǿ������� ����4�̴�. 
	if (sum == 2) {
		// ����4�� ���� Ư���ϰ� ���ٿ� 44�� �ɼ� �ִ�.
		// 1234567   12345678
		// 0 0 0 0   00  0 00
		// ���� ���� ��Ȳ���� 4��ġ�� ���� ���̸�
		// ������ ��� 4�� �Ǿ� ���ٿ��� 44�� �߻��Ѵ�.
		// ������ 0000 �̿Ͱ��� �����϶��� 4�� �ϳ��̱� ������
		// �˻縦 �Ͽ� ������ ��Ȯ�ϰ� �Ѵ�. 
		if (GetStoneCount_2016182043(x, y, nStone, nDir) == 4) sum = 1;
	}
	// sum�� 2�� �ƴϸ� ����4�� �ƴϹǷ� 0 
	else sum = 0;

	return sum;
}

bool rule_IsDoubleFour_2016182043(int x, int y, int nStone)
{
	int cnt = 0;

	//��ǥ�� �߽����� ������ �ٿ����Ͽ� 4�� �˻��Ѵ�. 
	for (int i = 0; i < 8; i += 2) {
		// OpenFour()������ �� �ٿ� 44�� ���� �� ������ �˻��ϰ� 
		if (IsOpenFour_2016182043(x, y, nStone, i) == 2) return true;
		// ����4�� 4�̴� 4�� �˻��Ͽ� 2�� �̻��̸� 44�̴�. 
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
			// 33�� ���� �ϳ� �� ������ �� �ݵ�� ����4�̾�� �ǰ�, 
			// �� �� ���� �ڸ��� 44, 6��, �Ǵٸ� 33 
			// �� �ݼ��ڸ��� �ƴϾ�� �ȴ�.
			if ((rule_IsOpenFour_2016182043(tx, ty, nStone, nDir) == 1) && (!rule_IsForbidden_2016182043(tx, ty, nStone))) {
				// �� ������ �����ϴ� �ڸ��̸� 3�̹Ƿ� ���� �����ϰ� ���� �����Ѵ�. 
				nBoard_2016182043[y][x] = empty_2016182043;
				return true;
			}
		}
	}

	nBoard_2016182043[y][x] = empty_2016182043;
	return false;
}

// 33�� �˻��Ѵ�. 
bool rule_IsDoubleThree_2016182043(int x, int y, int nStone)
{
	int cnt = 0;

	for (int i = 0; i < 8; i += 2) {
		if (rule_IsOpenThree_2016182043(x, y, nStone, i)) cnt++;
		if (cnt >= 2) return true;
	}

	return false;
}

// �ݼ��ڸ��� �˻��Ѵ�. 
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

	// �Ʒ� �Լ��� ������� ������ ���Ͽ� �ô�. 
	// ������ ���� ���� ������ �ϴ� �˰����̶�
	// �� �� ���� ���� ���ϰ� �ּ��� ���� �ѻ��̴�. 
	int arrWeight[] = { 2, 5, 10, 30, 35, 300 };
	//int (COMOKAI::*fp[6])(int, int, int, int) = { IsTwo_2016182043, IsOpenTwo_2016182043, IsThree_2016182043, IsOpenThree_2016182043, IsFour_2016182043, yourOpenFour_2016182043 };

	// �����Ͽ� ��ü������ ������ �ʿ��ؼ� 
	// ���� ������ �Ǹ� �׶� ������ ÷���ϰڽ�.
	// OpenFour�� ��� ����� ���� ���� ��� ���� ���� ���
	// ������ �켱���� �ַ��� ������ �޸� �غý�.

	// ����4�� �ִµ��� ����� 43�ڸ��� ������ �װ� ���� ���Ƽ� 
	// ���ַ꿡�� ���� 6���� �� �� �ֱ� ������ 6��� �� �ִ� 
	// OpenFour�� ���� ���Ͽ� �����ϰ� �����غ��� ������ ����
	// ���� ���� �ý��۰� ���������� �պ��� �� �� 
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