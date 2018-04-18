#include"stdafx.h"

#include<iostream>
#include<fstream>
#include<random>
#include<chrono>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

#define MAX_PLAYER 100
const int maxTrainingScore = 37000000;
const unsigned int maxPrisonScore = 410000000;



class RankingData
{
public:
	RankingData()
	{
		strcpy(id , "NULL");
		rank = 0;
		//ratio = 0;
		trainingGroundScore=0;
		prisonBreakScore=0;
	}
	RankingData(string idData, int trainingScore, int prisonScore) :trainingGroundScore(trainingScore), prisonBreakScore(prisonScore)
	{
		strcpy(id, idData.c_str());
	};

	void Print()
	{
		cout.precision(3);
		cout << setw(30) << id << setw(7) << rank << "등 " <<setw(4) << ratio << "%" << "  쿠키훈련소 점수: " << setw(15) << trainingGroundScore << " 떼탈출소 점수: " << setw(15) << prisonBreakScore << endl;
	}
public:
	char id[30];
	unsigned int rank = 0;
	float ratio = 0;
	unsigned int trainingGroundScore;
	unsigned int prisonBreakScore;

};



int main()
{
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::normal_distribution<double> distribution(0.0, 0.5);

	std::vector<RankingData> rankingSystem;



	ifstream in("output.txt", ios::binary);

	if (in)
	{
		rankingSystem.resize(MAX_PLAYER);
		in.read((char*)rankingSystem.data(), sizeof(RankingData) * MAX_PLAYER);
		for (auto& data : rankingSystem)
		{
			data.Print();
		}
	}
	else
	{
		rankingSystem.reserve(MAX_PLAYER);
		for (int i = 0; i < MAX_PLAYER;)
		{
			double trainingScore = distribution(dre);
			double prisonScore = distribution(dre);

			if (-1.0 <= trainingScore && trainingScore <= 1.0 &&-1.0 <= prisonScore && prisonScore <= 1.0)
			{
				trainingScore += 1;
				prisonScore += 1;
				trainingScore *= 18500000;
				prisonScore *= 205000000;
				if (i == 0)
				{
					rankingSystem.emplace_back("나", int(trainingScore), int(prisonScore));
				}
				else
				{
					rankingSystem.emplace_back(to_string(i) + "번 플레이어", int(trainingScore), int(prisonScore));
				}
				i++;
			}
		}
	}




	auto start = std::chrono::high_resolution_clock::now();




	cout << "==================================================================================================================" << endl;

	sort(rankingSystem.begin(), rankingSystem.end(), [](const RankingData& a, const RankingData& b) {
		return a.trainingGroundScore + a.prisonBreakScore > b.trainingGroundScore + b.prisonBreakScore;
	});


	//qsort(rankingSystem.data(), rankingSystem.size(), sizeof(RankingData), [](const void* a, const void* b)
	//{
	//	return static_cast<const int>(((RankingData*)a)->prisonBreakScore+((RankingData*)a)->trainingGroundScore) - static_cast<const int>(((RankingData*)b)->prisonBreakScore + ((RankingData*)b)->trainingGroundScore);
	//});

	std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() - start;

	int rank = 1;
	int totalrank = 1;

	int size = rankingSystem.size();
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
		{
			if (rankingSystem[i - 1].prisonBreakScore + rankingSystem[i - 1].trainingGroundScore == rankingSystem[i].prisonBreakScore + rankingSystem[i].trainingGroundScore)
			{
				rankingSystem[i].rank = rank;
				rankingSystem[i].ratio = (rank / (float)MAX_PLAYER) * 100;
			}
			else
			{
				rankingSystem[i].rank = totalrank;
				rank = totalrank;
				rankingSystem[i].ratio = (rank / (float)MAX_PLAYER) * 100;
			}
		}
		else
		{
			rankingSystem[i].rank = rank;
			rankingSystem[i].ratio = (rank / (float)MAX_PLAYER) * 100;
		}
		rankingSystem[i].Print();
		totalrank++;
	}

	cout << elapsedTime.count()<<endl;


	cout << "==================================================================================" << endl;

	ofstream out("output.txt", ios::binary);

	out.write((char*)rankingSystem.data(), rankingSystem.size() * sizeof(RankingData));

}
