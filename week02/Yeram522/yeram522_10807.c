#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int N,V;
	int arr[100];
	int sum = 0;

	//�Է�
	scanf("%d", &N); //���� ����
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &V);

	for (int i = 0; i < N; i++)
	{
		if (arr[i] != V) continue;
		sum++;
	}

	printf("%d", sum);
		
	return 0;
}