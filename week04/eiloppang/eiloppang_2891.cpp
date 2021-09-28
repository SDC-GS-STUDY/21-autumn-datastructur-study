#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {

	int N, S, R;
	char team[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int team_number;
	int dont_go = 0;

	scanf("%d %d %d", &N, &S, &R);

	for (int i = 0; i < S; i++) {
		scanf("%d", &team_number);
		team[team_number]--;
	}

	for (int i = 0; i < R; i++) {
		scanf("%d", &team_number);
		team[team_number]++;
	}

	clock_t start = clock();

	for (int i = 1; i <= N; i++) {
		if (team[i] == 2) {
			if (team[i - 1] == 0) {
				team[i - 1]++;
				team[i]--;
			}
			else if (team[i + 1] == 0) {
				team[i + 1]++;
				team[i]--;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (team[i] == 0)
			dont_go++;
	}

	printf("%d\n", dont_go);

	clock_t end = clock();

	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

}