#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

bool IsFirst(int _N,int* _votes)//��ȣ1���� �迭�� �ִ����� Ȯ���Ѵ�.
{
	for (int i = 1; i < _N; i++)
	{
		if (_votes[0] <= _votes[i]) return false;//�ϳ��� ��ȣ1������ ���ų� ������ ������ �ٷ� return false.
		if (i == _N - 1) return true;
	}
}

bool ctex(int _N, int* _votes)
{
	for (int i = 1; i < _N; i++)
	{
		if (_votes[0] < _votes[i]) return false;//�ϳ��� ��ȣ1������ ������ ������ �ٷ� return false.
		if (i == _N - 1) return true;//������ Ž������ �� 1������ �۰ų� ������ true;
	}
}

int main()
{
	int N;//N: �� ��ȸ�ǿ� �ĺ� ��, M: ���� �ֹ�
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
		for (int i = 1; i < N; i++)//votes[0]=�ټ�(��ȣ1��)
		{
			if (IsFirst(N, votes)) break;
			if (votes[0] >= votes[i] && !ctex(N, votes))continue;//�ټ��̺��� ũ�ų� ���� ��ǥ���� ���� ��� �Ʒ� ����.
			votes[i]--;
			votes[0]++;//����ĺ� ��ǥ���� �ϳ� ���´�.
			buying++;
		}
	}

	printf("%d", buying);

	return 0;
}