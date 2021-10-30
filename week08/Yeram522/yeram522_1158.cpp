#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> que;
	int N;
	int K;//몇번째?
	int count=1;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) que.push(i); //큐 채우기
	printf("<");

	while (que.size())//사람이 점점 줄어들어서 0이 될 때 까지.
	{
		for (int i = 0; i < K - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		if(que.size()!=1) printf("%d, ", que.front());
		else printf("%d>", que.front());
		que.pop();
	}

	return 0;
}