#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main()
{
	int N;
	int ropes[100000];
	int index;
	int Max=0;

	//입력
	scanf("%d", &N);

	//동적할당

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &ropes[i]);//입력

		//오름차순 정렬
		/*if (i == 0 || ropes[i - 1] <= ropes[i]) continue;
		for (int j = i; 0 <= j; j--)
		{
			if (ropes[j - 1] <= ropes[j]) continue;
			int temp = ropes[j];
			ropes[j] = ropes[j - 1];
			ropes[j - 1] = temp;
		}*/
		//------------
		//내림차순 정렬
		if (i == 0 || ropes[i - 1] >= ropes[i]) continue;
		for (int j = i; 0 < j; j--)
		{
			if ((i != 0 && i + 1 < N) && (ropes[j - 1] >= ropes[j] && ropes[j] >= ropes[j + 1])) break;
			if (ropes[j - 1] >= ropes[j]) continue;
			int temp = ropes[j];
			ropes[j] = ropes[j - 1];
			ropes[j - 1] = temp;
			index = j - 1;//입력 된 값의 최종 배열 인덱스
		}

		if (ropes[index] * (index + 1) > Max) Max = ropes[index] * (index + 1);
	}

	for(int i = 0; i<N;i++) printf("%d\n", ropes[i]);

	printf("ewsutl: %d", Max);

	return 0;
}