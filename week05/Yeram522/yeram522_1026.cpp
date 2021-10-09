#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

void quick_sort(int* data, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1; //왼쪽 출발 지점
	int j = end; // 오른쪽 출발 지점
	int temp;

	while (i <= j)
	{
		//포인터가 엇갈릴 떄 까지 반복
		while (i <= end && data[i] <= data[pivot]) i++;
		while(j > start&& data[j] >= data[pivot]) j--;

		if (i > j)
		{
			//엇갈림
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//분할계산
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main()
{
	int N;
	int A[50], B[50];
	int S = 0;
	int max;

	//입력
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	//-----

	//오름차순으로 퀵정렬
	quick_sort(A , 0, N - 1);
	quick_sort(B , 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		S += A[i] * B[N - i - 1];
	}

	printf("%d", S);

	return 0;
}