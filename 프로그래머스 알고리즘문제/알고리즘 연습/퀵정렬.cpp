#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void QuickSort(vector<T>& v, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int i = start - 1;
	int pivot = end;

	for (int j = start; j < pivot; j++)
	{
		if (v[j] <= v[pivot])
		{
			swap(v[++i], v[j]);
		}
	}

	swap(v[++i], v[pivot]);

	QuickSort(v, start, i - 1);
	QuickSort(v, i+1,end);

}




void Merge(vector<int>& v, int start,int mid, int end)
{
	vector<int> sorted;
	
	int i = start;
	int j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (v[i] < v[j])
		{
			sorted.push_back(v[i]);
			i += 1;
		}
		else
		{
			sorted.push_back(v[j]);
			j += 1;
		}
	}

	while (i <= mid)
	{
		sorted.push_back(v[i]);
		i += 1;
	}
	while (j <= end)
	{
		sorted.push_back(v[j]);
		j += 1;
	}

	int index = 0;

	for (int i = start; i <= end; i++)
	{
		v[i] = sorted[index];
		index += 1;
	}
}

void Divide(vector<int>& v, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Divide(v, start, mid);
		Divide(v, mid+1,end);
		Merge(v, start, mid, end);
	}
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(rand() % 100);
	}

	Divide(v, 0, v.size() - 1);

	//QuickSort(v, 0, v.size() - 1);

	for (auto data : v)
	{
		cout << data << " ";
	}

}