#pragma once
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

class RankingData
{
public:
	RankingData():rank(0),trainingGroundScore(0),prisonBreakScore(0),ratio(0) {	strcpy(id, "NULL");	}
	~RankingData();
	RankingData(string idData, int trainingScore, int prisonScore) :trainingGroundScore(trainingScore), prisonBreakScore(prisonScore) {strcpy(id, idData.c_str());}

	void Print();
	inline string getId()const { return string(id); }
	inline pair<unsigned int, unsigned int> getScore()const	{ return pair<unsigned int, unsigned int>(trainingGroundScore, prisonBreakScore);}
	inline int getRank()const { return rank; }
	inline int getPreviousRank()const { return previousRank; }
	inline int getTrainScore()const { return trainingGroundScore; }
	inline int getPrisonScore()const { return prisonBreakScore; }

	inline void setScore(const pair<unsigned int, unsigned int>& param) { trainingGroundScore = param.first; prisonBreakScore = param.second; }
	inline void setTrainScore(const int param) { trainingGroundScore = param; }
	inline void setPrisonScore(const int param) { prisonBreakScore = param; }
	inline void setRank(const int param) { rank = param; }
	inline void setpreviousRank(const int param) { previousRank = param; }
	inline void setRatio(const float param) { ratio = param; }
private:
	char id[30];
	unsigned int rank = 0;
	float ratio = 0;
	unsigned int trainingGroundScore;
	unsigned int prisonBreakScore;
	unsigned int previousRank = 0;
};

