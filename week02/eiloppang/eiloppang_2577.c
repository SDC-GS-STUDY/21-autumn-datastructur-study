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
		arr[result % 10]++; // ������ �����̴ϱ� 0~9 �� ���� ������ �ش� �ε����� ++
		result /= 10; // result = 0 �� ������ ��� �����µ� �̰� �� ����
	}


	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

}