#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

void Heapify(vector<int>& v, int i);

void BuildHeap(vector<int>& v)
{
	for (int i = (v.size() - 2) / 2; i >= 0; --i)
	{
		Heapify(v, i);
	}
}

vector<int> HeapSort(vector<int>& v)
{
	vector<int> sort;

	BuildHeap(v);
	int len = v.size();
	for (int i = 0; i < len-1; i++)
	{
		sort.push_back(v[0]);
		v[0] = v[v.size() - 1];
		v.erase(v.end() - 1);
		Heapify(v, 0);
	}
	sort.push_back( v[0]);

	return sort;
}


int main()
{
	vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		v.push_back(rand() % 100 + 1);
	}

	auto data = HeapSort(v);


	for (int i = 0; i < data.size(); ++i)
	{
		cout << data[i] << " ";
	}
}

void Heapify(vector<int>& v, int i)
{

	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int smaller = 0;

	if (right <= v.size() - 1)
	{
		if (v[left] < v[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= v.size() - 1)
	{
		smaller = left;
	}
	else
		return;


	if (v[i] > v[smaller])
	{
		swap(v[i], v[smaller]);
		Heapify(v, smaller);
	}

}
