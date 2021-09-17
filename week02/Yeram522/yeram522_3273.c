#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int value(int _sequence[], int _n_sequence); //_n_sequence = N_sequence[i]

int main()
{
	clock_t start, finish;
	double duration;
	int sum = 0;

	int length, Num;
	int result=0;

	start = clock();

	//<�Է�>
	scanf("%d", &length); //������ ����

	int* sequence = (int*)malloc(sizeof(sequence) * length); //�����Ҵ�
	int* N_sequence = (int*)malloc(sizeof(N_sequence) * length); //�����Ҵ�

	for (int i = 0; i < length; i++)
	{
		scanf("%d", &sequence[i]);//�Է� ���� ������ �迭 �ʱ�ȭ. (������ ��.)
		N_sequence[i]=i+1;//������ ���� �迭(a1,a2,a3,a4.....)->���� �������� ����. sequence�� �����̶���.
	}	
	scanf("%d", &Num); //�ڿ��� X

	//-(1) ������ �������� ����!(��������)
	for (int i = length; 0 < i; i--)
	{
		for (int j = 0; j < i-1; j++)
		{
			int max;
			if (value(sequence, N_sequence[j]) > value(sequence, N_sequence[j + 1]))
			{
				max = N_sequence[j];
				N_sequence[j] = N_sequence[j+1];
				N_sequence[j+1] = max;				
			}
		}			
	}

	//-(2) Ž��

	for (int i = 0; i < length; i++)
	{
		if ((N_sequence[i] < N_sequence[length - i - 1]) && (value(sequence, N_sequence[i]) + value(sequence, N_sequence[length-i-1]) == Num))
		{
			result++;
		}
	}

	
	printf("%d\n", result);

	free(sequence);
	free(N_sequence);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f�� �Դϴ�.", duration);
	
}

int value(int _sequence[], int _n_sequence) //_n_sequence = N_sequence[i]
{
	return _sequence[_n_sequence - 1];
}

