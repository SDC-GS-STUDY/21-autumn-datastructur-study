#include <stdio.h>

int main(void) {
	int max = 100, sum = 0;
	int wrong[9];

	for (int i = 0; i < 9; i++) {
		scanf_s("%d", &wrong[i]);
		sum += wrong[i];
	}

	int true = sum - 100;
	int a, lie1 = 0, lie2 = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			a = wrong[i] + wrong[j];

			if (a == true) {
				lie1 = i, lie2 = j;
				break;
			}
		}
	}

	int k = 0;
	int correct[7];
	for (int i = 0; i < 9; i++) {
		if (i != lie1 && i != lie2) {
			correct[k] = wrong[i];
			k++;
		}
	}

	int temp;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (correct[i] > correct[j]) {
				temp = correct[i];
				correct[i] = correct[j];
				correct[j] = temp;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		printf("%d\n", correct[i]);
	}




}