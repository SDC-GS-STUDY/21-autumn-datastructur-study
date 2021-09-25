#include <stdio.h>

int main() {
	int A, B, C;
	int arr[10] = { 0, };
	int result = 0;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	result = A * B * C;

	while (result > 0) {
		arr[result % 10]++; // 나머지 연산이니까 0~9 이 생길 때마다 해당 인덱스에 ++
		result /= 10; // result = 0 될 때까지 계속 나누는데 이건 몫만 남음
	}


	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

}