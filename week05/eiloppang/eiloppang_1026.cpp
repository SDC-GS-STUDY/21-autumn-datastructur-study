#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int a[50] = { 0, };
	int b[50] = { 0, };
	int sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	} // ��¥ �̷� �� Ʋ�ȴٰ� �Ѵ� ���� ��¥ ���̰� ���

	// ��������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (a[j] > a[j + 1]) {
				int tmp1;
				tmp1 = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp1;
			}
		}
	}
	
	// ��������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (b[j + 1] > b[j]) {
				int tmp2;
				tmp2 = b[j + 1];
				b[j + 1] = b[j];
				b[j] = tmp2;
			}
		}
	}

	for (int i = 0; i < N; i++)
		sum += (a[i] * b[i]);

	printf("%d", sum);
}