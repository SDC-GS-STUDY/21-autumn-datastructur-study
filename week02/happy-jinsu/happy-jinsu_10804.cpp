#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int card[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };	
	int i, j, r,tmp,start,end;

	for (r = 0; r < 10; r++)
	{
		scanf("%d%d", &start, &end);                          //구간 입력과 동시에 정렬
		i = start - 1;
		j = end - 1;

		while (1)                                             // 해당 구간만 바꾸기
		{
			if (j <= i)
			{
				break;
			}

			tmp = card[i];
			card[i] = card[j];
			card[j] = tmp;

			i++;
			j--;
		}
	}
	
	for (i = 0; i < 20; i++) 
	{
		printf("%d ", card[i]);
	}

	return 0;
}