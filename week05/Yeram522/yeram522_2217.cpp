#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main()
{
	int N;
	int ropes[100000];
	int index;
	int Max=0;

	//�Է�
	scanf("%d", &N);

	//�����Ҵ�

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &ropes[i]);//�Է�

		//�������� ����
		/*if (i == 0 || ropes[i - 1] <= ropes[i]) continue;
		for (int j = i; 0 <= j; j--)
		{
			if (ropes[j - 1] <= ropes[j]) continue;
			int temp = ropes[j];
			ropes[j] = ropes[j - 1];
			ropes[j - 1] = temp;
		}*/
		//------------
		//�������� ����
		if (i == 0 || ropes[i - 1] >= ropes[i]) continue;
		for (int j = i; 0 < j; j--)
		{
			if ((i != 0 && i + 1 < N) && (ropes[j - 1] >= ropes[j] && ropes[j] >= ropes[j + 1])) break;
			if (ropes[j - 1] >= ropes[j]) continue;
			int temp = ropes[j];
			ropes[j] = ropes[j - 1];
			ropes[j - 1] = temp;
			index = j - 1;//�Է� �� ���� ���� �迭 �ε���
		}

		if (ropes[index] * (index + 1) > Max) Max = ropes[index] * (index + 1);
	}

	for(int i = 0; i<N;i++) printf("%d\n", ropes[i]);

	printf("ewsutl: %d", Max);

	return 0;
}