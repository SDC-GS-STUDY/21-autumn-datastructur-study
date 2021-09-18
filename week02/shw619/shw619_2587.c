#include <stdio.h>

int main() {

	int avg = 0, temp, sum = 0;
	int num[5];

	for (int i = 0; i < 5; i++) {

		scanf_s("%d", &num[i]);
		sum += num[i];
	}

	avg = sum / 5;

	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++) {

			if (num[i] > num[i + 1]) {

				temp = num[i+1];
				num[i+1] = num[i];
				num[i] = temp;
			}
		}
	}

	printf("%d\n%d", avg, num[2]);

	return 0;
}
