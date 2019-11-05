#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;


struct adJustment
{
	adJustment(int a, int b) :weight(a), data(b) {}
	int weight;
	int data;
	int prev;
};

struct Node
{
	vector<adJustment> adj;
};

class Graph
{
public:
	vector<Node> nodes;
	Graph(int num)
	{
		nodes.resize(num);
	}
	void AddEdge(int from, int to, int weight)
	{
		nodes[from].adj.emplace_back( weight, to );
	}
};

// 오름차순 정렬
struct cmp {
	bool operator()(pair<int, int> t, pair<int, int> u) {
		return t.first > u.first;
	}
};

void Dijkstra(Graph& g, int v)
{
	priority_queue < pair<int, int>, vector<pair<int,int>> ,cmp> q;
	vector<int> costs;
	costs.resize(g.nodes.size(),INT_MAX);

	costs[v] = 0;

	for (int i = 0; i < g.nodes.size(); ++i)
	{
		q.push(make_pair(costs[i],i));
	}


	while (!q.empty())
	{
		auto select = q.top();
		q.pop();
		for (auto i : g.nodes[select.second].adj)
		{
			cout << select.second << " " << i.data << endl;
			if (costs[select.second] + i.weight < costs[i.data])
			{
				costs[i.data] = costs[select.second] + i.weight;
				i.prev = select.second;
			}
		}
	}
}

int main()
{
	Graph g(5);


	//for (int i = 0; i < 20; i++)
	//{
	//	int a = rand() % 11;
	//	int b = rand() % 11;
	//	int c = rand() % 20 + 1;
	//	if (a == b)
	//	{
	//		i -= 1;
	//		continue;
	//	}
	//	cout << a << " " << b << endl;

	//}
	g.AddEdge(0, 1, 10);
	g.AddEdge(0, 2, 10);
	g.AddEdge(0, 3, 5);
	g.AddEdge(3, 4, 1);
	g.AddEdge(1, 4, 7);

	Dijkstra(g, 0);
}