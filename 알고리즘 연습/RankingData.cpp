#include "RankingData.h"


RankingData::~RankingData()
{
}

void RankingData::Print()
{
	cout.precision(3);
	cout << setw(30) << id << setw(7) << rank << "µî " << setw(4) << ratio << "%" << "   ÄíÅ°ÈÆ·Ã¼Ò Á¡¼ö: " << setw(15) << trainingGroundScore << "  ¶¼Å»Ãâ¼Ò Á¡¼ö: " << setw(15) << prisonBreakScore << endl;
}
