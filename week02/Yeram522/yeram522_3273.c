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

	//<입력>
	scanf("%d", &length); //수열의 길이

	int* sequence = (int*)malloc(sizeof(sequence) * length); //동적할당
	int* N_sequence = (int*)malloc(sizeof(N_sequence) * length); //동적할당

	for (int i = 0; i < length; i++)
	{
		scanf("%d", &sequence[i]);//입력 받은 값으로 배열 초기화. (수열의 값.)
		N_sequence[i]=i+1;//수열의 순서 배열(a1,a2,a3,a4.....)->예로 오름차순 정렬. sequence의 별명이랄까.
	}	
	scanf("%d", &Num); //자연수 X

	//-(1) 수열의 오름차순 정렬!(버블정렬)
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

	//-(2) 탐색

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
	printf("%f초 입니다.", duration);
	
}

int value(int _sequence[], int _n_sequence) //_n_sequence = N_sequence[i]
{
	return _sequence[_n_sequence - 1];
}

