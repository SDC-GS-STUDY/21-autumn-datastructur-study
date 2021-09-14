#include <stdio.h>
int main() {

	int arr[9];
	int large = 0;
	int maxNum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > large) {
			large = arr[i];
			maxNum = i;
		}
	}

	printf("%d \n%d", large, maxNum + 1);

	return 0;
}