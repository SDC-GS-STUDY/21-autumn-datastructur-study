#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, sum=0, N, tmp, time[1000], MinTime=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &time[i]);

	for (i = 0; i < N-1; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (time[i] > time[j])
			{
				tmp = time[i];
				time[i] = time[j];
				time[j] = tmp;
			}
	
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
			sum += time[j];

		MinTime += sum;
		sum = 0;
	}

	printf("%d", MinTime);
}