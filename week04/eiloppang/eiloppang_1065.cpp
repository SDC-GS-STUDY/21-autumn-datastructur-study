#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
	int N;
	int arr[10] = { 0, };
	int hanSu = 99;
	
	
	scanf("%d", &N);

	clock_t start = clock();

	if (N < 100) {
		printf("%d", N);
		return 0;
	} // �� �ڸ��������� �׳� �� �Ѽ���

	for (int i = 100; i <= N; i++) {
		int a, b, c;

		a = i / 100; // ���� �ڸ�
		b = (i % 100) / 10; // ���� �ڸ�
		c = (i % 100) % 10; // ���� �ڸ�

		if ((a - b) == (b - c))
			hanSu++;

	}
	printf("%d\n", hanSu); // �� �ڸ�������

	clock_t end = clock();

	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}