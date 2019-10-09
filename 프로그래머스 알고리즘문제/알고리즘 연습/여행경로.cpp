#include <string>
#include <vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


#include<iostream>


struct Node
{
	vector<bool> isVisit;
	vector<string> adjustment;
};

class Graph
{
public:
	unordered_map<string,Node> nodes;
	int ticketCount = 0;

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

	bool DFS(string start, vector<string>& answer, vector<string>& temp)
	{
		if (temp.size() == ticketCount )
		{
			temp.push_back(start);
			answer = temp;
			return true;
		}
	

		temp.push_back(start);

		auto& adjustments = nodes[start].adjustment;
		auto& visit = nodes[start].isVisit;

		for (int j = 0; j < adjustments.size(); ++j)
		{
			int index = j;
			if (!visit[index])
			{
				//cout << start << " -> " << adjustments[index] << endl;
				visit[index] = true;
				bool success = DFS(adjustments[index], answer, temp);

				if (success)
					return true;

				visit[index] = false;
			}
		}

		temp.pop_back();
		return false;
	}

	void InitDFS(string start, vector<string>& answer, vector<string>& temp)
	{

		DFS(start,answer,temp);
	}

};

vector<string> solution(vector<vector<string>> tickets) {
	
	
	
	vector<string> answer;
	vector<string> temp;


	sort(tickets.begin(), tickets.end());

	Graph graph;
	for (int i = 0; i < tickets.size(); ++i)
	{
		graph.AddEdge(tickets[i][0], tickets[i][1]);
	}
	graph.ticketCount = tickets.size();
	graph.InitDFS("ICN",answer, temp);





	return answer;
}


int main()
{
	
	auto temp = solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"},{"HND","ICN"},{"ICN","HND"} });


	for (auto data : temp)
	{
		cout << data << " ";
	}
}