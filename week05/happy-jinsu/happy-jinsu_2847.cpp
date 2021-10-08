#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, N, OutZero = 0, Variation = 0, Stage[100] = { 0 };

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &Stage[i]);

	while (1)
	{
		for (i = 0; i < N - 1; i++)
		{
			while (1)
			{
				if (Stage[i] >= Stage[i + 1])
				{
					Stage[i]--;
					Variation++;
					OutZero++;
					if (Stage[i] < 0)
					{
						Stage[i]++;
						Stage[i + 1]++;
					}
				}
				if (Stage[i] < Stage[i + 1])
					break;
			}
		}
		if (OutZero == 0)
		{
			printf("%d", Variation);
			break;
		}
		else
			OutZero = 0;
	}	
	return 0;
}