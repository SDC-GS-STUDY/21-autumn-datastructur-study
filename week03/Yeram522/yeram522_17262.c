#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int N;

	int* Spt;
	int* Ept;

	int result[2];

	//[1] 입력: 욱제의 팬의 수를 입력 받는다. 1 <= N <= 100,000
	scanf("%d", &N);

	Spt = (int*)malloc(sizeof(int) * N);//팬의 수 만큼 동적할당.
	Ept = (int*)malloc(sizeof(int) * N);//팬의 수 만큼 동적할당.

	//[2] 팬의 수 만큼 팬이 학교에 있는 시간을 입력 받는다.
	for (int i = 0; i < N; i++)//[3] 값받으면서 s의 최대 e의 최소 구하기! 
	{
		scanf("%d %d", &Spt[i], &Ept[i]);
		if (i == 0)
		{
			result[0] = Spt[i];
			result[1] = Ept[i];
		}
		if (result[0] < Spt[i])result[0] = Spt[i];
		if (result[1] > Ept[i]) result[1] = Ept[i];

	}

	//머무는 시간 [s,e] e<s가 성립하면 s-e
	//e>=s이면 0이다.
	if (result[0] > result[1]) printf("%d", result[0] - result[1]);
	else printf("%d", 0);

}
