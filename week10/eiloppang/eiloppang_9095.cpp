#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number[12] = { 0, };

int main() {
	int T;
	scanf("%d", &T);

	number[0] = 1; // x == 1 
	number[1] = 2; // x == 2
	number[2] = 4; // x == 3

	int testCase;
	for (int i = 0; i < T; i++) {
		scanf("%d", &testCase);
		for (int j = 3; j < testCase; j++) {
			number[j] = number[j - 3] + number[j - 2] + number[j - 1];
		}
		printf("%d\n", number[testCase - 1]);
	}

}