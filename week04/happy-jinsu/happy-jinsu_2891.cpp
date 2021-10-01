#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int N, S, R, i, num, Out = 0, Kayak[10] = { 0 };

	scanf("%d %d %d", &N, &S, &R);
	for (i = 0; i < S; i++)
	{
		scanf("%d", &num);
		Kayak[num-1] = -1;
	}

	for (i = 0; i < R; i++)
	{
		scanf("%d", &num);
		Kayak[num-1] ++;
	}

	for (i = 0; i <= N; i++)
	{
		if (Kayak[i] == -1 && Kayak[i-1] == 1)
		{
			Kayak[i]++;
			Kayak[i - 1]--;
		}

		if (Kayak[i] == -1 && Kayak[i + 1] == 1)
		{
			Kayak[i]++;
			Kayak[i + 1]--;
		}

		if (Kayak[i] == -1)
			Out++;
	}
	printf("%d", Out);
}