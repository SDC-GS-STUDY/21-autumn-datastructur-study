#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FAN(int i);
int num, a, b,i, sum, MAX = 0, MIN = 100000, sum;
int main(void)
{
	scanf("%d", &num);
	FAN(num);

	sum = MAX - MIN;

	if (sum < 0)
	{
		sum = 0;
	}
	printf("%d", sum);

	return 0;
}

int FAN(int i) 
{
	if (i > 0) {
		scanf("%d %d", &a, &b);

		if (a > MAX)
			MAX = a;

		if (b < MIN)
			MIN = b;

		return FAN(num - 1);
	}
	else
		return 0;
}
