/*
�� N���� ������ �־����� ��, ���� v�� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
#include <stdio.h>

int main(void) {

	int size = 0; //������ ����
	int num[100];
	int findNum;
	int count = 0;


	scanf_s("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &num[i]);
	}
	scanf_s("%d", &findNum);

	for (int i = 0; i < size; i++)
	{
		if (num[i] == findNum)
			count++;
	}

	printf("%d", count);

	return 0;
}