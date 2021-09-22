#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Prime(int _N) //소수가 아니면 0을 반환하고, 소수이면 소수를 반환한다.
{
	if (_N < 2) return 0;//예와 상황 처음에 신경안써가지구 틀림처리 나왔음.ㅠㅠ
	for (int i = 2; i < _N/2+1; i++)
		if (_N % i == 0) return 0;		

	return _N;
}

int main()
{
	//입력
	int Min;
	int Max;
	scanf("%d", &Min);
	scanf("%d", &Max);

	int Sum = 0;
	int N = Min;
	while (N <= Max)
	{
		int prime = Prime(N);
		Sum += prime; //return 0이 아니면 소수이므로 소수를 Sum값에 더한다.
		if (prime !=0 && (Sum-prime)==0) Min = prime;
		N += 1;
	}

	if (Sum == 0)
	{
		printf("%d\n", -1);
		return 0;
	}
	
	printf("%d\n%d", Sum, Min);
	
}