#include <stdio.h>

int main(void)
{
	int N, max = 0, key = 0, res = 0, temp = 0;
	int A[50] = { 0, };
	int B[50] = { 0, };	

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &B[i]);
	}

	for (int i = 0; i < N-1; i++) //오름차순
	{
		for (int j = 0; j < N-1-i; j++)
		{
			if (A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}	

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (B[i] > max) {
				max = B[i];
				key = i;
			}
		}		

		res += B[key] * A[j];

		B[key] = -1; //쓰레기
		max = -1;	 //쓰레기
	}

	printf("%d", res);

	return 0;
}