#include "RankingData.h"


RankingData::~RankingData()
{
}

void RankingData::Print()
{
	cout.precision(3);
	cout << setw(30) << id << setw(7) << rank << "�� " << setw(4) << ratio << "%" << "   ��Ű�Ʒü� ����: " << setw(15) << trainingGroundScore << "  ��Ż��� ����: " << setw(15) << prisonBreakScore << endl;
}
