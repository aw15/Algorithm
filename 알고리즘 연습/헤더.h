#pragma once
/*
100000만명 데이터 만들기

리저브X, 푸시백 - 1.27455
리저브O, 푸시백 - 0.97999
리저브O, emplace - 0.969323
리저브X , emplace - 1.29034

리저브X, 이동, emplace - 1.40973
리저브o, 이동, emplace- 1.05121
정수 변수 3개의 이동연산은 오히려 시간 손해가 생긴라고 볼수도 있지만 오차범위내에서 시간차이기 때문에 확정할 수는 없다.


노말분포 설명

#include <iomanip>
setw(15)로 출력 자릿수를 지정해서 선을 맞출수 있었다.

이동생성자만 만들고 sort함수를 쓰니 에러가 났다.
대입연사자 오버로딩이 필요했다.
sort함수 내부에서 대입연산자 오버로딩을 쓰는것 같다.

					100개	100000개
sort로 했을 때 0.00251461    0.194119
qsort로 했을때 0.00288923    0.0904765


디버그 
sort 6.61268
qsort 1.98354

qsort가 오히려 빨랐다...
이유는 내가 깊은복사를 하는 이동연산자를 만들었기 때문이었다

컴파일러가 알아서 복사생성자와 대입연산자를 만들었을 때
qsort 0.0670892
sort  0.0902558
으로 qsort가 빨랐다.

이동생성자를 빼고 복사생성자만 내가 넣을때도 결과는 같았다.

퀵정렬이 최악의 경우에는 O(n^2)이 되서 컴파일러가 알아서 복사생성자와 대입연산자를 만들었을 경우의 시간우위는
왔다갔다 했다.



sort함수는 리턴 타입이 bool 타입이라 1번만 비교하면 되지만
qsort는 리턴 타입이 int 타입이라 3가지 경우의 수가 있어 3번은 비교해야 합니다.
qsort의 스왑함수는 void*로 인수를 받기 때문에 실제 데이터의 크기와정보를 알수가 없습니다. 
그래서 qsort함수의 3번째 인자(데이터크기)를 기준으로 객체의 혹은 타입의 크기만큼 전체복사를 구현하게 됩니다.

sort
sort함수의 경우는 템플릿을 이용한 복사입니다.


for (auto& data : rankingSystem)로 반복문을 돌았을때 100명이 다나오지 않고 98명만 나왔다.
for (int i = 0; i <= MAX_PLAYER; i++) 돌자 모두 다 나왔다.



RankingData(RankingData& copy)
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;
}
RankingData(RankingData&& copy) noexcept
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;
}
RankingData operator=(const RankingData& copy)
{
id = copy.id;
trainingGroundScore = copy.trainingGroundScore;
prisonBreakScore = copy.prisonBreakScore;

return *this;
}
RankingData operator=(const RankingData&& copy)
{
	id = copy.id;
	trainingGroundScore = copy.trainingGroundScore;
	prisonBreakScore = copy.prisonBreakScore;

	return *this;
}
연산자 만들면 오히려 최적화의 손해가 많이 생겼다.
아무래도 컴파일러가 만드는 코드가 더 효율적인거 같다.


sort후에 메모리 위치가 바뀌다보니 처음 find if로 찾았던 player iterator가 더 이상 player가 아니었다.


auto temp = player++;
이런식으로 하면 대입연산자가 먼저이기 때문에 원본player가 temp에 들어가고 오히려 player가 다음껄 가리키게 된다.
*/


