#include<iostream>
#include<vector>


using namespace std;


vector<int> v;

void DFS(int i, vector<bool> visit, vector<int> temp)
{
	if (visit[i])
		return;


	visit[i] = true;
	temp.push_back(v[i]);

	if (temp.size() == 6)
	{
		for (auto& data : temp)
		{
			printf("%d ", data);
		}
		printf("\n");
		return;
	}

	for (int j = i+1; j < v.size(); j++)
	{
		if (!visit[j])
		{
			DFS(j, visit, temp);
		}
	}

}

int main()
{


	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		v.clear();
		int temp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			v.push_back(temp);
		}

		vector<bool> visit;
		visit.resize(v.size(), false);
		vector<int> tempV;

		for (int i = 0; i <= v.size() - 6; ++i)
		{
			DFS(i, visit, tempV);
		}

		printf("\n");
	}


}