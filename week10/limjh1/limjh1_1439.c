#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char arr[1000000] = { 0, };
	int changePoint = 0;
	int result = 0;

	scanf("%s", &arr);

	int i = 0;

	while (1) {

		if (arr[i] == '\0') break;

		if (arr[i] != arr[i + 1])
		{
			changePoint++;
		}
		i++;		

		if (changePoint == 2)
		{
			result++;
			changePoint = 0;
		}
	}

	printf("%d", result);

	return 0;
}