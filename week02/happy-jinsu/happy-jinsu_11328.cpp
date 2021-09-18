#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char NumCase[1000], NumCase1[1000];
	int result[1000] = { 0 };
	int i,n,k=0,sum=0,N;

	scanf("%d", &n);
	N = n;

	while (1)
	{
		scanf("%s%s", NumCase, NumCase1);
		n--;

		for (i = 0; i < strlen(NumCase); i++)       
		{
			sum = sum + (NumCase[i] - 97);
			sum = sum - (NumCase1[i] - 97);

			if (strlen(NumCase) != strlen(NumCase1))
			{
				i = strlen(NumCase) - 1;
				result[k] = 1;
				k++;
				break;
			}
			if (i == strlen(NumCase)-1)
			{
				if (sum == 0)
				{
					result[k] = 0;
					k++;
					break;
				}

				else
				{
					result[k] = 1;
					k++;
					break;
				}
			}
		}
		if (n == 0)
			break;
	}
	
	for (i = 0; i < N; i++)
	{
		if (result[i] == 0)
			printf("Possible\n");

		else
			printf("Impossible\n");
	}
	return 0;
}