#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int M, N, sum = 0, MIN, i, j, k = 0, num[10000];
	scanf("%d %d", &M, &N);
	for (i = M; i <= N; i++)
	{
		if (i == 2)
		{
			num[k] = i;
			k++;
		}
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
			if (j == i - 1 && i % j != 0)
			{
				num[k] = i;
				k++;
			}
		}
	}
	MIN = num[0];
	for (i = 0; i < k; i++)
	{
		sum += num[i];

		if (num[i] < MIN)
			MIN = num[i];
	}

	if (k == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, MIN);
}