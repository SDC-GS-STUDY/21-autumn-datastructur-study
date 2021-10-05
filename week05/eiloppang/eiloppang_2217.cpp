#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; // 오름차순 (C언어 도장 https://dojang.io/mod/page/view.php?id=638)
	// return *(int*)b - *(int*)a; 내림차순 (C언어 도장)
}

int main() {
	int N;
	
	scanf("%d", &N);

	int* weight = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}

	qsort(weight, N, sizeof(int), compare); // 처음에는 버블 정렬을 했는데, 그렇게 하면 시간초과가 뜸
											// 시간초과가 뜨는 이유가 for문 2번 돌려서 시간 복잡도 O(n^2) 돼서 .. 그래서 어쩔 수 없이 qsort 사용

	int count = N;
	int max = 0;
	int realMaxWeight = 0;
	for (int i = 0; i < N; i++) {
		max = weight[i] * count--; // (N-1)*다음 정렬[i] 곱하면서 가장 무겁게 들 수 있는 걸 찾는 과정
		if (realMaxWeight < max)
			realMaxWeight = max; // 가장 무겁게 들 수 있는 거 찾는 걸 업데이트 하는 과정
	}

	printf("%d", realMaxWeight);

	free(weight);
}