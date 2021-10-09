#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;  // 런타임 에러가 나서 이렇게 해결함.

int main()
{
	int NumberOfRopes, tmp, i, MIN = 0, MAX = 0, Weight;
	
	scanf("%d", &NumberOfRopes);
	int* Rope = (int*)malloc(sizeof(int) * NumberOfRopes); // 동적할당

	for (i = 0; i < NumberOfRopes; i++)                    // 입력받기
		scanf("%d", &Rope[i]);
	
	sort(Rope, Rope + NumberOfRopes);                      // 작은 수 부터 정렬.
	MIN = 0;                                                 // j 초기화.

	for (i = NumberOfRopes; i > 0; i--)                    // 줄 수를 줄여가며 MAX값 비교.
	{
		Weight = Rope[MIN] * i;
		MIN++;

		if (Weight > MAX)
			MAX = Weight;
	}

	printf("%d",MAX);
	free(Rope);                                             // 메모리 해제
	return 0;
}