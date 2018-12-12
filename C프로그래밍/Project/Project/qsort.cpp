#include<iostream>

using namespace std;

int partition(int* arr, int begin, int end);
int i = 0;
void swap(int* arr, int a,int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void printarr(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void quickSort(int* arr, int begin, int end) {
	if (begin < end) {
		int p = partition(arr, begin, end);
		quickSort(arr, begin, p - 1);
		quickSort(arr, p + 1, end);
	}
}

int partition(int* arr, int begin, int end) {
	int left = begin;
	int right = end;

	int pivot = (left + right) / 2;

	cout<<"[퀵 정렬 " <<++i << "단계: pivot: " << arr[pivot]<<endl;

	while (left < right) {
		while ((arr[left] < arr[pivot]) && (left < right))
			// L 움직이는 부분
			left++;
		while ((arr[right] >= arr[pivot]) && (left < right))
			// R 움직이는 부분
			right--;

		if (left < right) {
			swap(arr, left, right);
		}
	}

	swap(arr,pivot, right);

	printarr(arr,10);

	return left;
}


int main()
{
	int num[10] = { 11,21,31,12,22,32,13,23,33,10 };

	quickSort(num, 0,9);

	printarr(num, 10);
}