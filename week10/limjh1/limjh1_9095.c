#include <stdio.h>

int inputNum = 0; // ������ ����
int arr[11]; // 11���� �۴�

int recursionFunc(int input)
{
	arr[1] = 1; // 1
	arr[2] = 2; // 1+1 , 2
	arr[3] = 4; // 1+1+1, 1+2 , 2+1, 3

	for (int i = 4; i <= inputNum; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	return arr[input];
}

int main(void)
{
	int num = 0; // �� Ƚ��
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &inputNum);
		printf("%d\n", recursionFunc(inputNum));		
	}

	return 0;
}
