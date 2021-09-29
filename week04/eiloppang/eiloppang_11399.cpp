#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
	int N;
	int P[1001] = { 0, };
	int tmp;
	int sum = 0;
	int min = 0;

	scanf("%d", &N);
	

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	clock_t start = clock();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (P[j] > P[j + 1]) {	// 버블 정렬 사용
				tmp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = tmp;
			}
		}
	} // 작은 애부터 세우기

	for (int i = 0; i < N; i++) {
		// P[0]은 무조건 선택해도 된다 -> 0은 계속 더 해지는 최적해의 조건
		sum += P[i];
		min += sum; // 계속 그 앞의 값이 적재되는 느낌?
	}
	
	printf("%d\n", min);

	clock_t end = clock();
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}