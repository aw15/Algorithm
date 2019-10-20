#include<iostream>
#include<vector>
#include<set>
using namespace std;

void Partition(int arr[], int p, int r)
{
	if (p >= r)
	{
		return;
	}


	int pivot = arr[r];
	int i = p - 1;
	for (int j = p; j < r ; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr[++i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r]);
	i = i + 1;

	Partition(arr, p, i - 1);
	Partition(arr, i+1,r);
}


struct Node
{
	char c;
	bool isVisit = false;
};

int dx[4] = { -1,+1,0,0 };
int dy[4] = { 0,0,-1,1 };


class Graph
{
public:
	vector<vector<Node>> nodes;
	bool isVisit[26] = { false, };
	int h;
	int w;
	int answer = 0;

	void Init(int w, int h)
	{
		this->w = w;
		this->h = h;
		nodes.resize(h);
		char temp;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; ++j)
			{
				scanf("%c", &temp);
				nodes[i].push_back({ temp , false});
			}
			getchar();
		}
	}



	void DFS( int x, int y, int count)
	{
	
		if (count > answer)
		{
			answer = count;
		}
			
		
		for(int i=0;i<4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;

			int alpha = nodes[nx][ny].c - 'A';

			if (isVisit[alpha])
				continue;

			isVisit[alpha] = true;
			DFS(nx, ny, count + 1);
			isVisit[alpha] = false;
		}
	}
};

int main()
{
	int arr[] = { 12,24,32,12,23,25,99,11 };
	Partition(arr, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}

	//Graph g;
	//int w, h;
	//scanf("%d %d", &h, &w);
	//getchar();
	//g.Init(w, h);
	//set<char> s;

	//g.isVisit[g.nodes[0][0].c - 'A'] = true;
	//g.DFS(0,0,1);

	//
	//printf("%d", g.answer);

	//cout << g.answer;

}