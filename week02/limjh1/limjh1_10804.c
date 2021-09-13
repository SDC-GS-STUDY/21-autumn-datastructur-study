/*
오름차순으로 한 줄로 놓여있는 20장의 카드에 대해 10개의 구간이 주어지면, 
주어진 구간의 순서대로 위의 규칙에 따라 순서를 뒤집는 작업을 연속해서 처리한 뒤 마지막 카드들의 배치를 구하는 프로그램을 작성하시오.
*/

#include <stdio.h>

int main(void) {

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int swap = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d %d", &c, &d); // c~d 범위

		a = c - 1;
		b = d - 1;

		for (int i = 0; i < (b - a + 1) / 2; i++)
		{
			swap = arr[b - i];
			arr[b - i] = arr[a + i];
			arr[a + i] = swap;
		}
	}	
	
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr[i]);
	}	

	return 0;
}