#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; // �������� (C��� ���� https://dojang.io/mod/page/view.php?id=638)
	// return *(int*)b - *(int*)a; �������� (C��� ����)
}

int main() {
	int N;
	
	scanf("%d", &N);

	int* weight = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}

	qsort(weight, N, sizeof(int), compare); // ó������ ���� ������ �ߴµ�, �׷��� �ϸ� �ð��ʰ��� ��
											// �ð��ʰ��� �ߴ� ������ for�� 2�� ������ �ð� ���⵵ O(n^2) �ż� .. �׷��� ��¿ �� ���� qsort ���

	int count = N;
	int max = 0;
	int realMaxWeight = 0;
	for (int i = 0; i < N; i++) {
		max = weight[i] * count--; // (N-1)*���� ����[i] ���ϸ鼭 ���� ���̰� �� �� �ִ� �� ã�� ����
		if (realMaxWeight < max)
			realMaxWeight = max; // ���� ���̰� �� �� �ִ� �� ã�� �� ������Ʈ �ϴ� ����
	}

	printf("%d", realMaxWeight);

	free(weight);
}