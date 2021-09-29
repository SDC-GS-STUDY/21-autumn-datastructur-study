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
	} // 두 자릿수까지는 그냥 다 한수임

	for (int i = 100; i <= N; i++) {
		int a, b, c;

		a = i / 100; // 백의 자리
		b = (i % 100) / 10; // 십의 자리
		c = (i % 100) % 10; // 일의 자리

		if ((a - b) == (b - c))
			hanSu++;

	}
	printf("%d\n", hanSu); // 세 자릿수부터

	clock_t end = clock();

	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}