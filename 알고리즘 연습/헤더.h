#pragma once
/*
100000���� ������ �����

������X, Ǫ�ù� - 1.27455
������O, Ǫ�ù� - 0.97999
������O, emplace - 0.969323
������X , emplace - 1.29034

������X, �̵�, emplace - 1.40973
������o, �̵�, emplace- 1.05121
���� ���� 3���� �̵������� ������ �ð� ���ذ� ������ ������ ������ �������������� �ð����̱� ������ Ȯ���� ���� ����.


�븻���� ����

#include <iomanip>
setw(15)�� ��� �ڸ����� �����ؼ� ���� ����� �־���.

�̵������ڸ� ����� sort�Լ��� ���� ������ ����.
���Կ����� �����ε��� �ʿ��ߴ�.
sort�Լ� ���ο��� ���Կ����� �����ε��� ���°� ����.

					100��	100000��
sort�� ���� �� 0.00251461    0.194119
qsort�� ������ 0.00288923    0.0904765


����� 
sort 6.61268
qsort 1.98354

qsort�� ������ ������...
������ ���� �������縦 �ϴ� �̵������ڸ� ������� �����̾���

�����Ϸ��� �˾Ƽ� ��������ڿ� ���Կ����ڸ� ������� ��
qsort 0.0670892
sort  0.0902558
���� qsort�� ������.

�̵������ڸ� ���� ��������ڸ� ���� �������� ����� ���Ҵ�.

�������� �־��� ��쿡�� O(n^2)�� �Ǽ� �����Ϸ��� �˾Ƽ� ��������ڿ� ���Կ����ڸ� ������� ����� �ð�������
�Դٰ��� �ߴ�.



sort�Լ��� ���� Ÿ���� bool Ÿ���̶� 1���� ���ϸ� ������
qsort�� ���� Ÿ���� int Ÿ���̶� 3���� ����� ���� �־� 3���� ���ؾ� �մϴ�.
qsort�� �����Լ��� void*�� �μ��� �ޱ� ������ ���� �������� ũ��������� �˼��� �����ϴ�. 
�׷��� qsort�Լ��� 3��° ����(������ũ��)�� �������� ��ü�� Ȥ�� Ÿ���� ũ�⸸ŭ ��ü���縦 �����ϰ� �˴ϴ�.

sort
sort�Լ��� ���� ���ø��� �̿��� �����Դϴ�.


for (auto& data : rankingSystem)�� �ݺ����� �������� 100���� �ٳ����� �ʰ� 98�� ���Դ�.
for (int i = 0; i <= MAX_PLAYER; i++) ���� ��� �� ���Դ�.



RankingData(RankingData& copy)
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;
}
RankingData(RankingData&& copy) noexcept
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;
}
RankingData operator=(const RankingData& copy)
{
id = copy.id;
trainingGroundScore = copy.trainingGroundScore;
prisonBreakScore = copy.prisonBreakScore;

return *this;
}
RankingData operator=(const RankingData&& copy)
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;

	return *this;
}
������ ����� ������ ����ȭ�� ���ذ� ���� �����.
�ƹ����� �����Ϸ��� ����� �ڵ尡 �� ȿ�����ΰ� ����.


sort�Ŀ� �޸� ��ġ�� �ٲ�ٺ��� ó�� find if�� ã�Ҵ� player iterator�� �� �̻� player�� �ƴϾ���.


auto temp = player++;
�̷������� �ϸ� ���Կ����ڰ� �����̱� ������ ����player�� temp�� ���� ������ player�� ������ ����Ű�� �ȴ�.
*/


