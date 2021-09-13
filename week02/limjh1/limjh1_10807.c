/*
총 N개의 정수가 주어졌을 때, 정수 v가 몇 개인지 구하는 프로그램을 작성하시오.
*/
#include <stdio.h>

int main(void) {

	int size = 0; //정수의 개수
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