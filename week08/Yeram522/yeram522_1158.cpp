#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> que;
	int N;
	int K;//���°?
	int count=1;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) que.push(i); //ť ä���
	printf("<");

	while (que.size())//����� ���� �پ�� 0�� �� �� ����.
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