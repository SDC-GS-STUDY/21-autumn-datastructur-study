#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int score[100] = { 0, };
	int minNum = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &score[i]);

	for (int i = N - 1; i > 0; i--) {
		while (score[i] <= score[i - 1]) {
			score[i - 1]--;
			minNum++;
		}
	}

	printf("%d", minNum);
}