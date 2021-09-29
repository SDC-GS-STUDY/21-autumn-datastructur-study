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
			if (P[j] > P[j + 1]) {	// ���� ���� ���
				tmp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = tmp;
			}
		}
	} // ���� �ֺ��� �����

	for (int i = 0; i < N; i++) {
		// P[0]�� ������ �����ص� �ȴ� -> 0�� ��� �� ������ �������� ����
		sum += P[i];
		min += sum; // ��� �� ���� ���� ����Ǵ� ����?
	}
	
	printf("%d\n", min);

	clock_t end = clock();
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}