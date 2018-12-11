

#include"RankingData.h"

#define MAX_PLAYER 100000


int main()
{
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::normal_distribution<double> distribution(0.0, 0.5);
	std::uniform_int_distribution<int> selectPlayer(0,99999);
	std::vector<RankingData> rankingSystem;



	ifstream in("output.txt", ios::binary);

	if (in)
	{
		rankingSystem.resize(MAX_PLAYER);
		in.read((char*)rankingSystem.data(), sizeof(RankingData) * MAX_PLAYER);
		cout << "파일입출력 성공" << endl;
	}
	else
	{
		cout << "초기 데이터 생성" << endl;
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

		sort(rankingSystem.begin(), rankingSystem.end(), [](const RankingData& a, const RankingData& b) {
			return a.getTrainScore() + a.getPrisonScore() > b.getTrainScore() + b.getPrisonScore();
		});

		int rank = 1;
		int totalrank = 1;

		int size = rankingSystem.size();



		for (int i = 0; i < size; i++)
		{
			if (i != 0)
			{
				if (rankingSystem[i - 1].getPrisonScore() + rankingSystem[i - 1].getTrainScore() == rankingSystem[i].getPrisonScore() + rankingSystem[i].getTrainScore())
				{
					rankingSystem[i].setRank(rank);
					rankingSystem[i].setRatio((rank / (float)MAX_PLAYER) * 100);
				}
				else
				{
					rankingSystem[i].setRank(totalrank);
					rank = totalrank;
					rankingSystem[i].setRatio((rank / (float)MAX_PLAYER) * 100);
				}
			}
			else
			{
				rankingSystem[i].setRank(rank);
				rankingSystem[i].setpreviousRank(rank);
				rankingSystem[i].setRatio((rank / (float)MAX_PLAYER) * 100);
			}
			totalrank++;
		}
		auto player = find_if(rankingSystem.begin(), rankingSystem.end(), [](RankingData& data)
		{
			return (data.getId() == "나");
		});

		int myRank = player->getRank();
		player->setpreviousRank(myRank);

		player->Print();
		cout << endl << "-----------------------------------------------내 위 등수-----------------------------------------------" << endl;
		player--;
		while (myRank <= player->getRank())
		{
			player--;
		}
		player->Print();
		cout << endl << "----------------------------------------------내 아래 등수----------------------------------------------" << endl;
		player++;
		while (myRank >= player->getRank())
		{
			player++;
		}
		player->Print();


		cout << "==================================================================================================================" << endl;
	}


	

	int selection = -1;
	while (!(selection == 0))
	{
		auto start = std::chrono::high_resolution_clock::now();

		double trainingScore = distribution(dre);
		double prisonScore = distribution(dre);

		cout << "==================================================================================================================" << endl;

		auto player = find_if(rankingSystem.begin(), rankingSystem.end(), [](RankingData& data)
		{
			return (data.getId() == "나");
		});

		if (-1.0 <= trainingScore && trainingScore <= 1.0 &&-1.0 <= prisonScore && prisonScore <= 1.0)
		{
			auto previousScore = player->getScore();

			trainingScore += 1;
			prisonScore += 1;
			trainingScore *= 18500000;
			prisonScore *= 205000000;

			if (previousScore.first < trainingScore)
			{
				player->setTrainScore(trainingScore);
			}
			if (previousScore.second < prisonScore)
			{
				player->setPrisonScore(prisonScore);
			}
		}


		for (int i = 0; i < 9999;)
		{
			trainingScore = distribution(dre);
			prisonScore = distribution(dre);

			RankingData currentData = rankingSystem[selectPlayer(dre)];

			if (-1.0 <= trainingScore && trainingScore <= 1.0 &&-1.0 <= prisonScore && prisonScore <= 1.0)
			{
				auto previousScore = currentData.getScore();

				trainingScore += 1;
				prisonScore += 1;
				trainingScore *= 18500000;
				prisonScore *= 205000000;

				if (previousScore.first < trainingScore)
				{
					currentData.setTrainScore(trainingScore);
				}
				if (previousScore.second < prisonScore)
				{
					currentData.setPrisonScore(prisonScore);
				}

				i++;
			}
		}
		sort(rankingSystem.begin(), rankingSystem.end(), [](const RankingData& a, const RankingData& b) {
			return a.getTrainScore() + a.getPrisonScore() > b.getTrainScore() + b.getPrisonScore();
		});

		int rank = 1;
		int totalrank = 1;

		int size = rankingSystem.size();



		for (int i = 0; i < size; i++)
		{
			if (i != 0)
			{
				if (rankingSystem[i - 1].getPrisonScore() + rankingSystem[i - 1].getTrainScore() == rankingSystem[i].getPrisonScore() + rankingSystem[i].getTrainScore())
				{
					rankingSystem[i].setRank(rank);
					rankingSystem[i].setRatio ((rank / (float)MAX_PLAYER) * 100);
				}
				else
				{
					rankingSystem[i].setRank( totalrank);
					rank = totalrank;
					rankingSystem[i].setRatio ( (rank / (float)MAX_PLAYER) * 100);
				}
			}
			else
			{
				rankingSystem[i].setRank(rank);
				rankingSystem[i].setRatio((rank / (float)MAX_PLAYER) * 100);
			}
			totalrank++;
		}

		player = find_if(rankingSystem.begin(), rankingSystem.end(), [](RankingData& data)
		{
			return (data.getId() == "나");
		});

		int myRank = player->getRank();

		if (player->getPreviousRank() != 0)
		{
			cout <<  player->getPreviousRank()<<" 등 -------> " << myRank <<" 등" << endl;
		}
		player->setpreviousRank(myRank);


		player->Print();
		cout<<endl << "-----------------------------------------------내 위 등수-----------------------------------------------" << endl;
		player--;
		while (myRank <= player->getRank())
		{
			player--;
		}
		player->Print();
		cout<<endl << "----------------------------------------------내 아래 등수----------------------------------------------"<<endl;
		player++;
		while (myRank >= player->getRank())
		{
			player++;
		}
		player->Print();
	
		
		cout << "==================================================================================================================" << endl;
		std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() - start;

		cout << "수행시간 : " << elapsedTime.count() << endl;

		cout << "끝내시겠습니까?[ YES: 0 NO : 1 ] : ";
		cin >> selection;
	}



	
	

	


	//qsort(rankingSystem.data(), rankingSystem.size(), sizeof(RankingData), [](const void* a, const void* b)
	//{
	//	return static_cast<const int>(((RankingData*)a)->prisonBreakScore+((RankingData*)a)->trainingGroundScore) - static_cast<const int>(((RankingData*)b)->prisonBreakScore + ((RankingData*)b)->trainingGroundScore);
	//});

	
	ofstream out("output.txt", ios::binary);
	out.write((char*)rankingSystem.data(), rankingSystem.size() * sizeof(RankingData));
	cout << "output.txt로 출력!" << endl;
	cout << "==================================================================================================================" << endl;

}
