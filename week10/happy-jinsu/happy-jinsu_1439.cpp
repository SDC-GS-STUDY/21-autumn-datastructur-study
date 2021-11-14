#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char S[10000];
	int length, i, j, zero = 0, one = 0, switching = 0;
	
	scanf("%s",&S);
	length = strlen(S);

	for (i = 0; i < length; i++)
	{
		if (S[i] == '0')
		{
			zero++;
		}

		if (S[i] == '1')
		{
			one++;
		}
	}

	if (zero == 0 || one == 0)
	{
		printf("0");
		return 0;
	}

	if (zero >= one)
	{
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < length; j++)
			{
				if (S[j] == '0' && (S[j+1] == '1'|| j==length-1))
				{
					S[j] = '1';
					switching++;
				}

				else if(S[j] == '0' && S[j + 1] != '1')
				{
					S[j] = '1';
				}
			}
		}
	}

	else if (zero < one)
	{
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < length; j++)
			{
				if (S[j] == '1' && S[j + 1] == '0')
				{
					S[j] = '0';
					switching++;
				}

				else if (S[j] == '1' && S[j + 1] != '0')
				{
					S[j] = '0';
				}

			}
		}
	}

	printf("%d", switching);
}