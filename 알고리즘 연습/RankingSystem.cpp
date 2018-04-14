#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<random>
#include<chrono>
#include<vector>
#include<string>
#include <iomanip>
#include<algorithm>
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
	RankingData(string idData, int trainingScore, int prisonScore) :id(idData),trainingGroundScore(trainingScore),prisonBreakScore(prisonScore) {};
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
	void Print()
	{
		cout <<setw(30) << id << "  ÄíÅ°ÈÆ·Ã¼Ò Á¡¼ö: "<<setw(15) << trainingGroundScore << " ¶¼Å»Ãâ¼Ò Á¡¼ö: "<<setw(15) << prisonBreakScore << endl;
	}
public:
	string id;
	unsigned int trainingGroundScore;
	unsigned int prisonBreakScore;

};


int main()
{


	auto start = std::chrono::high_resolution_clock::now();
	std::vector<RankingData> rankingSystem;
	
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::normal_distribution<double> distribution(5.0,2.0);


	rankingSystem.reserve(MAX_PLAYER);
	rankingSystem.push_back(RankingData("³ª", int(distribution(dre))*maxTrainingScore / MAX_PLAYER, int(distribution(dre))*maxPrisonScore / MAX_PLAYER));

	for (int i = 1; i <= MAX_PLAYER; ++i)
	{
		double trainingScore = distribution(dre);
		double prisonScore = distribution(dre);
		if ((trainingScore >= 0.0) && (trainingScore < 10.0)&& (prisonScore >= 0.0) && (prisonScore < 10.0))
		{
			rankingSystem.emplace_back(to_string(i) + "¹ø ÇÃ·¹ÀÌ¾î", int(trainingScore)*maxTrainingScore / MAX_PLAYER, int(prisonScore)*maxPrisonScore / MAX_PLAYER);
		}
	}
	sort(rankingSystem.begin(), rankingSystem.end(), [](const RankingData& a, const RankingData& b) {
		return a.trainingGroundScore + a.prisonBreakScore < b.trainingGroundScore + b.prisonBreakScore;
	});

	std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() - start;

	for (auto& data : rankingSystem)
	{
		data.Print();
	}

	cout << elapsedTime.count();
}