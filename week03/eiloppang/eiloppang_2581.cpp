#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int M, N;
	int sum = 0;
	int FirstOfThem = 0;
	int min = 0;

	scanf("%d", &M);
	scanf("%d", &N);

	for (int i = M; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) {
				if (i == j) {
					sum += i;
					FirstOfThem++;
					if (FirstOfThem == 1)
						min = i;
					break;
				}
				else
					break;
			}
		}
	}

	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);

}