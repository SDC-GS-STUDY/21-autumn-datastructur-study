#include <stdio.h>

int main(void) {

	int Level, count = 0;
	int arr[100] = { 0, };
	scanf_s("%d", &Level);

	for (int i = 0; i < Level; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < Level-1; i++)
	{
		while (1) {
			if (arr[Level - i - 2] >= arr[Level - i-1]) {
				arr[Level - i - 2]--;
				count++;
			}
			if (arr[Level - i - 2] < arr[Level - i-1]) break;
		}
	}

	printf("%d", count);

	return 0;
}