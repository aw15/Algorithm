#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;



//배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

//예를 들어 array가[1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
//
//array의 2번째부터 5번째까지 자르면[5, 2, 6, 3]입니다.
//1에서 나온 배열을 정렬하면[2, 3, 5, 6]입니다.
//2에서 나온 배열의 3번째 숫자는 5입니다.

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