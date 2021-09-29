#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int N, n, i, j, Num[3];

	scanf("%d", &N);
	if (N < 100)
	{
		printf("%d", N);
		return 0;
	}
	n = 99;
	for (i = 100; i <= N; i++)
	{
		Num[0] = i % 10;
		Num[1] = (i % 100) / 10;
		Num[2] = i / 100;
		for (j = 0; j <= 4; j++)
		{
			if ((Num[2] - j == Num[1] && Num[1] - j == Num[0])|| (Num[0] - j == Num[1] && Num[1] - j == Num[2]))
			{
				n++;
				break;
			}
		}
	}
	printf("%d", n);
	return 0;
}
