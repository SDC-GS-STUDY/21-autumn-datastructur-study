#include <stdio.h>

// 퀵 소트 가져옴 https://ahdelron.tistory.com/44
// 양쪽 값 변경 
inline void swap(int* a, int* b)
{
    int temp = *a; *a = *b; *b = temp;
}

// 퀵소트 함수 
void quickSort(int arr[], int start, int end)
{
    // 종료 조건 
    if (start >= end) return;

    // 피벗 (왼쪽 고정)
    int nPivot = arr[start];

    int i = start, j = end;

    while (i < j)
    {
        // 피벗보다 작은 숫자를 찾아야 돼서 j가 먼저 감소
        while (nPivot < arr[j]) j--;
        while (i < j && nPivot >= arr[i]) i++;

        swap(arr + i, arr + j);
    }

    swap(arr + start, arr + j);

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}

int main(void)
{
	int max;
	int count; //로프 수
	int weight[100000] = { 0, }; //각 로프의 중량
    int res[100000] = { 0, }; //결과

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &weight[i]);
	}

    quickSort(weight, 0, count - 1);

    for (int i = 0; i < count; i++)
    {
        if (weight[count - 1] / weight[i] > 0) res[i] = weight[i] * (count-i);
    }

    max = res[0];

    for (int i = 0; i < count; i++)
    {
        if (res[i] > max) max = res[i];
    }

    printf("%d", max);

	return 0;
}