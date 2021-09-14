#include <stdio.h>

int main() {
	int arr[5];
	int sum = 0;
	int averageResult = 0;

	int temp;
	int median = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}


	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (arr[y] > arr[y + 1]) {
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
		}
	}

	averageResult = sum / 5;
	median = arr[3];


	printf("%d\n%d", averageResult, median);


	return 0;
}