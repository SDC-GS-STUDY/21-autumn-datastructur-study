#include <stdio.h>

int main() {

	int fake_arr[9];
	int i;
	int j;
	int temp;
	int sum = 0;
	int over = 0;
	
	for (i = 0; i < 9; i++) {
		scanf("%d", &fake_arr[i]);
		sum += fake_arr[i];
	}
	

	over = sum - 100;

	int one = 0;
	int two = 0;

	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if ((fake_arr[i] + fake_arr[j]) == over) {
				one = i;
				two = j;
				break;
			}
		}
	}

	int real_arr[7];
	j = 0;

	for (i = 0; i < 9; i++) {
		if (i != one && i != two) {
			real_arr[j] = fake_arr[i];
			j++;
		}
	}

	
	for (i = 0; i < 6; i++) {
		for (j = i + 1; j < 7; j++) {
			if (real_arr[i] > real_arr[j]) {
				temp = real_arr[i];
				real_arr[i] = real_arr[j];
				real_arr[j] = temp;
			}
		}
	}

	for (i = 0; i < 7; i++)
		printf("%d\n", real_arr[i]);


	return 0;


}