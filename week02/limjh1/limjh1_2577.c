/*
�� ���� �ڿ��� A, B, C�� �־��� �� A �� B �� C�� ����� ����� 0���� 9���� ������ ���ڰ� �� ���� ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� A = 150, B = 266, C = 427 �̶�� A �� B �� C = 150 �� 266 �� 427 = 17037300 �� �ǰ�, ����� ��� 17037300 ���� 0�� 3��, 1�� 1��, 3�� 2��, 7�� 2�� ������.
*/
#include <stdio.h>

int main(void) {

	int num1, num2, num3;
	int result;
	int n;
	char arr[10] = { 0 };

	scanf_s("%d %d %d", &num1, &num2, &num3);

	result = num1 * num2 * num3;
	
	while (result > 0) {
		n = result % 10;
		arr[n]++;
		result /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}