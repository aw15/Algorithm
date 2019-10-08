#include <string>
#include <vector>
#include<string>
#include<unordered_map>
using namespace std;


#include<iostream>

vector<string> realAnswer;

struct Node
{
	vector<bool> isVisit;
	vector<string> adjustment;
};

class Graph
{
public:
	unordered_map<string,Node> nodes;

	void AddEdge(string a, string b)
	{
		nodes[a].isVisit.push_back(false);
		nodes[a].adjustment.push_back(b);
	}

	bool AllPass(string start)
	{
		for (int i = 0; i < nodes[start].isVisit.size(); ++i)
		{
			if (!nodes[start].isVisit[i])
			{
				return false;
			}
		}
		return true;
	}

	void DFS(string start, vector<string>& answer)
	{
		if (AllPass(start))
			return;


		auto& adjustments = nodes[start].adjustment;
		auto& visit = nodes[start].isVisit;

		for (int j = 0; j < adjustments.size(); ++j)
		{
			for (int i = 0; i < adjustments.size(); ++i)
			{
				int index = (i + j) % adjustments.size();
				if (!visit[index])
				{
					answer.push_back(adjustments[index]);
					cout << start << " -> " << adjustments[index] << endl;
					visit[index] = true;
					DFS(adjustments[index], answer);
					break;
				}
			}
			cout <<"=============================="<< endl;

	/*		if (answer.size() == nodes.size())
			{
				for (auto data : answer)
				{
					cout << data<<" ";
				}

			}
			cout << endl;*/

			
			/*for (int z=0;z<visit.size();++z)
			{
				visit[z] = false;
			}*/
		}
	}

	void InitDFS(string start)
	{
		vector<string> answer;
		DFS(start,answer);
	}

};

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	Graph graph;
	for (int i = 0; i < tickets.size(); ++i)
	{
		graph.AddEdge(tickets[i][0], tickets[i][1]);
	}
	
	graph.InitDFS("ICN");





	return answer;
}


int main()
{
	
	solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"},{"HND","ICN"},{"ICN","HND"} });
}