#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {

	int N;
	scanf("%d", &N);

	int count = 0;
	int vote[1001] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d", &vote[i]);
	}

	clock_t start = clock();

	while (1) {
		int voteMost = 0;
		for (int i = 0; i < N; i++) {
			if (vote[i] >= vote[voteMost]) {
				voteMost = i;
			}
		}
		if (voteMost == 0)
			break;

		vote[0]++;
		vote[voteMost]--;
		count++;
	}

	printf("%d\n", count);

	clock_t end = clock();

	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	
}