#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, k, T, N, Buy = 0, Max = 0, StockPrices[1000] = { 0 };

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		Max = 0;
		Buy = 0;
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &StockPrices[j]);
			if (StockPrices[j] > Max)
			{
				Max = StockPrices[j];
			}

		}
		for (j = 0; j < N; j++)
		{
			if (StockPrices[j] >= Max)
			{
				Max = 0;
				for (k = j+1; k < N; k++)
				{
					if (StockPrices[k] > Max)
					{
						Max = StockPrices[k];
					}
				}
			}
			else if (StockPrices[j] < Max)
			{
				Buy += Max - StockPrices[j];
			}
		}
		printf("%d\n", Buy);
	}

	return 0;
}