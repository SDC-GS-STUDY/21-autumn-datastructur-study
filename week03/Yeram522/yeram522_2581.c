#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Prime(int _N) //�Ҽ��� �ƴϸ� 0�� ��ȯ�ϰ�, �Ҽ��̸� �Ҽ��� ��ȯ�Ѵ�.
{
	if (_N < 2) return 0;//���� ��Ȳ ó���� �Ű�Ƚᰡ���� Ʋ��ó�� ������.�Ф�
	for (int i = 2; i < _N/2+1; i++)
		if (_N % i == 0) return 0;		

	return _N;
}

int main()
{
	//�Է�
	int Min;
	int Max;
	scanf("%d", &Min);
	scanf("%d", &Max);

	int Sum = 0;
	int N = Min;
	while (N <= Max)
	{
		int prime = Prime(N);
		Sum += prime; //return 0�� �ƴϸ� �Ҽ��̹Ƿ� �Ҽ��� Sum���� ���Ѵ�.
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