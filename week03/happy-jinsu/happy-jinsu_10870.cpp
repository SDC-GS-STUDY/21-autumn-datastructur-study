#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Fibo[20] = {0,1};
	int n, i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		if (n == 1)
		{
			break;
		}
		Fibo[i + 2]= Fibo[i] + Fibo[i + 1];
	}
	printf("%d", Fibo[n]);
}