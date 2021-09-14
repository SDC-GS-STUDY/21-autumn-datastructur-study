#include <stdio.h>

int main() {
	int arr[5];
	int sum = 0;
	int len = sizeof(arr) / sizeof(int);
	int averageResult = 0;

	int temp;
	int median = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int x = 0; x < 4; x++) {
		for (int y = x + 1; y < 5; y++) {
			if (arr[y - 1] < arr[y]) {
				temp = arr[y];
				arr[y] = arr[y - 1];
				arr[y - 1] = temp;
			}
		}
	}

	averageResult = sum / len;
	median = arr[(len - 1) / 2];
	

	printf("%d\n%d", averageResult, median);


	return 0;
}