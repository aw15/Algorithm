#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;



//�迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�.

//���� ��� array��[1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��
//
//array�� 2��°���� 5��°���� �ڸ���[5, 2, 6, 3]�Դϴ�.
//1���� ���� �迭�� �����ϸ�[2, 3, 5, 6]�Դϴ�.
//2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�.

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	
	for (auto& command : commands)
	{
		int i = command[0];
		int j = command[1];
		int k = command[2];
		printf("%d %d %d\n", i, j, k);

		vector<int> num(array.begin() + (i-1), array.begin() + j);

		sort(num.begin(), num.end());
	
		answer.push_back(num[k-1]);
	}
	

	return answer;
}



int main()
{



	solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
}