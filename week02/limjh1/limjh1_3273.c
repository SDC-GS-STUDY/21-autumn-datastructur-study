/*
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 
자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int size;// 수열의 크기
	int resultNum = 0; //더해서 나올 값
	int count = 0;

	scanf_s("%d", &size);

	int *arr = malloc(sizeof(int) * size); //동적할당

	for (int i = 0; i < size; i++)	
	{
		scanf_s("%d", &arr[i]);
	}

	scanf_s("%d", &resultNum);
	
	for (int i = 0; i < size; i++) 
	{
		if (resultNum > arr[i]) // 시간 줄이기
		{
			for (int j = i; j < size; j++) 
			{
				if (arr[i] != arr[j])
				{
					if (resultNum == (arr[i] + arr[j]))
						count++;
				}
			}
		}
	}

	printf("%d", count);

	free(arr);
	
	return 0;
}