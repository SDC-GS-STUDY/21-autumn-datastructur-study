#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

void quick_sort(int* data, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1; //���� ��� ����
	int j = end; // ������ ��� ����
	int temp;

	while (i <= j)
	{
		//�����Ͱ� ������ �� ���� �ݺ�
		while (i <= end && data[i] <= data[pivot]) i++;
		while (j > start && data[j] >= data[pivot]) j--;

		if (i > j)
		{
			//������
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//���Ұ��
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main()
{
	int N;
	int ropes[100000];
	int index;
	int Max = 0;

	//�Է�
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &ropes[i]);//�Է�

	//������
	quick_sort(ropes, 0, N-1);

	for (int i = 0; i < N; i++)
	{
		if (ropes[N-i - 1] * (i+1) > Max) Max = ropes[N - i - 1] * (i + 1);
	}


	printf("%d", Max);

	return 0;
}