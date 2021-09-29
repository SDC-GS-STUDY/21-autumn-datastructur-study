#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

bool IsFirst(int _N,int* _votes)//기호1번이 배열중 최댓값인지 확인한다.
{
	for (int i = 1; i < _N; i++)
	{
		if (_votes[0] <= _votes[i]) return false;//하나라도 기호1번보다 같거나 많은게 있으면 바로 return false.
		if (i == _N - 1) return true;
	}
}

bool ctex(int _N, int* _votes)
{
	for (int i = 1; i < _N; i++)
	{
		if (_votes[0] < _votes[i]) return false;//하나라도 기호1번보다 많은게 있으면 바로 return false.
		if (i == _N - 1) return true;//끝까지 탐색했을 때 1번보다 작거나 같으면 true;
	}
}

int main()
{
	int N;//N: 총 국회의원 후보 수, M: 마을 주민
	int* votes;
	int buying = 0;

	scanf("%d", &N);

	votes = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &votes[i]);
	}

	//printf("bool:%d", IsFirst(N, votes));

	while (!IsFirst(N, votes))
	{
		for (int i = 1; i < N; i++)//votes[0]=다솜(기호1번)
		{
			if (IsFirst(N, votes)) break;
			if (votes[0] >= votes[i] && !ctex(N, votes))continue;//다솜이보다 크거나 같은 득표수를 가질 경우 아래 실행.
			votes[i]--;
			votes[0]++;//상대후보 득표수를 하나 뺏는다.
			buying++;
		}
	}

	printf("%d", buying);

	return 0;
}