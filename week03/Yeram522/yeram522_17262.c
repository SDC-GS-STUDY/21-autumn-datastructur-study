#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int N;

	int* Spt;
	int* Ept;

	int result[2];

	//[1] �Է�: ������ ���� ���� �Է� �޴´�. 1 <= N <= 100,000
	scanf("%d", &N);

	Spt = (int*)malloc(sizeof(int) * N);//���� �� ��ŭ �����Ҵ�.
	Ept = (int*)malloc(sizeof(int) * N);//���� �� ��ŭ �����Ҵ�.

	//[2] ���� �� ��ŭ ���� �б��� �ִ� �ð��� �Է� �޴´�.
	for (int i = 0; i < N; i++)//[3] �������鼭 s�� �ִ� e�� �ּ� ���ϱ�! 
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

	//�ӹ��� �ð� [s,e] e<s�� �����ϸ� s-e
	//e>=s�̸� 0�̴�.
	if (result[0] > result[1]) printf("%d", result[0] - result[1]);
	else printf("%d", 0);

}
