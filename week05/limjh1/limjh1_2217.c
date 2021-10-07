#include <stdio.h>

// �� ��Ʈ ������ https://ahdelron.tistory.com/44
// ���� �� ���� 
inline void swap(int* a, int* b)
{
    int temp = *a; *a = *b; *b = temp;
}

// ����Ʈ �Լ� 
void quickSort(int arr[], int start, int end)
{
    // ���� ���� 
    if (start >= end) return;

    // �ǹ� (���� ����)
    int nPivot = arr[start];

    int i = start, j = end;

    while (i < j)
    {
        // �ǹ����� ���� ���ڸ� ã�ƾ� �ż� j�� ���� ����
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
	int count; //���� ��
	int weight[100000] = { 0, }; //�� ������ �߷�
    int res[100000] = { 0, }; //���

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